/* Common definitions for Intel 386 and AMD x86-64 systems using
   GNU userspace. */

/* The svr4 ABI for the i386 says that records and unions are returned
   in memory.  In the 64bit compilation we will turn this flag off in
   ix86_option_override_internal, as we never do pcc_struct_return
   scheme on this target.  */
#undef DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 1

/* We arrange for the whole %fs segment to map the tls area.  */
#undef TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
#define TARGET_TLS_DIRECT_SEG_REFS_DEFAULT MASK_TLS_DIRECT_SEG_REFS

#define TARGET_OS_CPP_BUILTINS()				\
  do								\
    {								\
	GNU_USER_TARGET_OS_CPP_BUILTINS();			\
    }								\
  while (0)

#undef CPP_SPEC
#define CPP_SPEC "%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"

#undef GNU_USER_TARGET_CC1_SPEC
#define GNU_USER_TARGET_CC1_SPEC "%(cc1_cpu) %{profile:-p}"

#undef CC1_SPEC
#define CC1_SPEC GNU_USER_TARGET_CC1_SPEC

/* Similar to standard GNU userspace, but adding -ffast-math support.  */
#define GNU_USER_TARGET_MATHFILE_SPEC \
  "%{mdaz-ftz:crtfastmath.o%s;Ofast|ffast-math|funsafe-math-optimizations:%{!shared:%{!mno-daz-ftz:crtfastmath.o%s}}} \
   %{mpc32:crtprec32.o%s} \
   %{mpc64:crtprec64.o%s} \
   %{mpc80:crtprec80.o%s}"

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC \
  GNU_USER_TARGET_MATHFILE_SPEC " " \
  GNU_USER_TARGET_ENDFILE_SPEC

#define TARGET_ASM_FILE_END file_end_indicate_exec_stack

/* The stack pointer needs to be moved while checking the stack.  */
#define STACK_CHECK_MOVING_SP 1

/* Static stack checking is supported by means of probes.  */
#define STACK_CHECK_STATIC_BUILTIN 1

/* We only build the -fsplit-stack support in libgcc if the
   assembler has full support for the CFI directives.  Also
   we only support -fsplit-stack on glibc targets.  */
#if (DEFAULT_LIBC == LIBC_GLIBC) && HAVE_GAS_CFI_PERSONALITY_DIRECTIVE
#define TARGET_CAN_SPLIT_STACK
#endif
