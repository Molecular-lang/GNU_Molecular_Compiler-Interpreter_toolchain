/* DWARF2 EH unwinding support for GNU Hurd: x86.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Do code reading to identify a signal frame, and set the frame
   state data appropriately.  See unwind-dw2.c for the structs. */

#ifndef inhibit_libc

#include <signal.h>

#define MD_FALLBACK_FRAME_STATE_FOR x86_gnu_fallback_frame_state

static _Unwind_Reason_Code
x86_gnu_fallback_frame_state
(struct _Unwind_Context *context, _Unwind_FrameState *fs)
{
  struct handler_args {
    int signo;
    union
      {
	struct
	  {
	    long int sigcode;
	    struct sigcontext *scp;
	  } legacy;
	struct
	  {
	    siginfo_t *siginfop;
	    ucontext_t *uctxp;
	  } posix;
      };
  } *handler_args;
  long int sigcode;
  unsigned long usp;

/*
 * i386 sigtramp frame we are looking for follows.
 * (see glibc/sysdeps/mach/hurd/i386/trampoline.c assembly)
 *
 * rpc_wait_trampoline:
 *   0:	b8 e7 ff ff ff       	mov    $-25,%eax       mach_msg_trap
 *   5:	9a 00 00 00 00 07 00 	lcall  $7,$0
 *  12:	89 01                	movl   %eax, (%ecx)
 *  14:	89 dc                	movl   %ebx, %esp      switch to signal stack
 *
 * trampoline:
 *  16:	ff d2                	call   *%edx           call the handler function
 * RA HERE
 *  18:	83 c4 0c             	addl   $12, %esp       pop its args
 *  21:	c3                   	ret                    return to sigreturn
 *
 * firewall:
 *  22:	f4                   	hlt
 */

  if (!(   *(unsigned int   *)(context->ra     ) == 0xc30cc483
        && *(unsigned char  *)(context->ra +  4) ==       0xf4

        && *(unsigned int   *)(context->ra -  4) == 0xd2ffdc89
        && *(unsigned int   *)(context->ra -  8) == 0x01890007
        && *(unsigned int   *)(context->ra - 12) == 0x00000000
        && *(unsigned int   *)(context->ra - 16) == 0x9affffff
        && *(unsigned short *)(context->ra - 18) ==     0xe7b8))
    return _URC_END_OF_STACK;

  handler_args = context->cfa;
  sigcode = handler_args->legacy.sigcode;
  if (sigcode >= -16 && sigcode < 4096)
    {
      /* This cannot be a SIGINFO pointer, assume legacy.  */
      struct sigcontext *scp = handler_args->legacy.scp;
      usp = scp->sc_uesp;

      fs->regs.reg[0].loc.offset = (unsigned long)&scp->sc_eax - usp;
      fs->regs.reg[1].loc.offset = (unsigned long)&scp->sc_ecx - usp;
      fs->regs.reg[2].loc.offset = (unsigned long)&scp->sc_edx - usp;
      fs->regs.reg[3].loc.offset = (unsigned long)&scp->sc_ebx - usp;
      fs->regs.reg[5].loc.offset = (unsigned long)&scp->sc_ebp - usp;
      fs->regs.reg[6].loc.offset = (unsigned long)&scp->sc_esi - usp;
      fs->regs.reg[7].loc.offset = (unsigned long)&scp->sc_edi - usp;
      fs->regs.reg[8].loc.offset = (unsigned long)&scp->sc_eip - usp;
    }
  else
    {
      /* This is not a valid sigcode, assume SIGINFO.  */
      ucontext_t *uctxp = handler_args->posix.uctxp;
      gregset_t *gregset = &uctxp->uc_mcontext.gregs;
      usp = (*gregset)[REG_UESP];

      fs->regs.reg[0].loc.offset = (unsigned long)&(*gregset)[REG_EAX] - usp;
      fs->regs.reg[1].loc.offset = (unsigned long)&(*gregset)[REG_ECX] - usp;
      fs->regs.reg[2].loc.offset = (unsigned long)&(*gregset)[REG_EDX] - usp;
      fs->regs.reg[3].loc.offset = (unsigned long)&(*gregset)[REG_EBX] - usp;
      fs->regs.reg[5].loc.offset = (unsigned long)&(*gregset)[REG_EBP] - usp;
      fs->regs.reg[6].loc.offset = (unsigned long)&(*gregset)[REG_ESI] - usp;
      fs->regs.reg[7].loc.offset = (unsigned long)&(*gregset)[REG_EDI] - usp;
      fs->regs.reg[8].loc.offset = (unsigned long)&(*gregset)[REG_EIP] - usp;
    }

  fs->regs.cfa_how = CFA_REG_OFFSET;
  fs->regs.cfa_reg = 4;
  fs->regs.cfa_offset = usp - (unsigned long) context->cfa;

  fs->regs.reg[0].how = REG_SAVED_OFFSET;
  fs->regs.reg[1].how = REG_SAVED_OFFSET;
  fs->regs.reg[2].how = REG_SAVED_OFFSET;
  fs->regs.reg[3].how = REG_SAVED_OFFSET;
  fs->regs.reg[5].how = REG_SAVED_OFFSET;
  fs->regs.reg[6].how = REG_SAVED_OFFSET;
  fs->regs.reg[7].how = REG_SAVED_OFFSET;
  fs->regs.reg[8].how = REG_SAVED_OFFSET;

  fs->retaddr_column = 8;
  fs->signal_frame = 1;

  return _URC_NO_REASON;
}

#endif /* ifndef inhibit_libc */
