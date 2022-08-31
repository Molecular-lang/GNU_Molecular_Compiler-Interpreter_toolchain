/* Configuration for an i386 running GNU with ELF as the target machine.  */

/* Please review: $(src-dir)/SPL-README for Licencing info. */

#define GNU_USER_LINK_EMULATION "elf_i386"

#undef GNU_USER_DYNAMIC_LINKER
#define GNU_USER_DYNAMIC_LINKER "/lib/ld.so"

#undef	STARTFILE_SPEC
#if defined HAVE_LD_PIE
#define STARTFILE_SPEC \
  "%{!shared: %{pg|p|profile:%{static:gcrt0.o%s;:gcrt1.o%s};pie:Scrt1.o%s;static:crt0.o%s;:crt1.o%s}} \
   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
#else
#define STARTFILE_SPEC \
  "%{!shared: %{pg|p|profile:%{static:gcrt0.o%s;:gcrt1.o%s};static:crt0.o%s;:crt1.o%s}} \
   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
#endif

#ifdef TARGET_LIBC_PROVIDES_SSP

/* i386 glibc provides __stack_chk_guard in %gs:0x14.  */
#define TARGET_THREAD_SSP_OFFSET        0x14

/* We only build the -fsplit-stack support in libgcc if the
   assembler has full support for the CFI directives.  Also
   we only support -fsplit-stack on glibc targets.  */
#if (DEFAULT_LIBC == LIBC_GLIBC) && HAVE_GAS_CFI_PERSONALITY_DIRECTIVE
#define TARGET_CAN_SPLIT_STACK
#endif
/* We steal the last transactional memory word.  */
#define TARGET_THREAD_SPLIT_STACK_OFFSET 0x30
#endif
