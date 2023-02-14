/* Definitions for kOpenSolaris-based GNU systems with ELF format */

#undef GNU_USER_TARGET_OS_CPP_BUILTINS    
#define GNU_USER_TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
	builtin_define ("__OpenSolaris_kernel__");	\
	builtin_define ("__GLIBC__");		\
	builtin_define_std ("unix");		\
	builtin_assert ("system=unix");		\
	builtin_assert ("system=posix");	\
    }						\
  while (0)

#undef GNU_USER_DYNAMIC_LINKER
#define GNU_USER_DYNAMIC_LINKER "/lib/ld.so.1"
