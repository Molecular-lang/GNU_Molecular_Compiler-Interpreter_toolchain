/* Prologue stub for 64-bit ms/sysv clobbers: save (with hard frame pointer)
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <cet.h>

#ifdef __x86_64__
#include "i386-asm.h"

/* Prologue routine for saving 64-bit ms/sysv registers when realignment is
 * needed or hard frame pointer used.  */

	.text
MS2SYSV_STUB_BEGIN(savms64f_17)
	mov	%r15,-0x68(%rax)
MS2SYSV_STUB_BEGIN(savms64f_16)
	mov	%r14,-0x60(%rax)
MS2SYSV_STUB_BEGIN(savms64f_15)
	mov	%r13,-0x58(%rax)
MS2SYSV_STUB_BEGIN(savms64f_14)
	mov	%r12,-0x50(%rax)
MS2SYSV_STUB_BEGIN(savms64f_13)
	mov	%rbx,-0x48(%rax)
MS2SYSV_STUB_BEGIN(savms64f_12)
	mov	%rdi,-0x40(%rax)
	mov	%rsi,-0x38(%rax)
	SSE_SAVE
	ret
MS2SYSV_STUB_END(savms64f_12)
MS2SYSV_STUB_END(savms64f_13)
MS2SYSV_STUB_END(savms64f_14)
MS2SYSV_STUB_END(savms64f_15)
MS2SYSV_STUB_END(savms64f_16)
MS2SYSV_STUB_END(savms64f_17)

#endif /* __x86_64__ */

#if defined(__ELF__) && defined(__linux__)
	.section .note.GNU-stack,"",@progbits
	.previous
#endif
