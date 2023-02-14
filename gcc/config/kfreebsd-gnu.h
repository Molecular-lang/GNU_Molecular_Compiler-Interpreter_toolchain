/* Definitions for kFreeBSD-based GNU systems with ELF format */

#define GNU_USER_TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
	builtin_define ("__FreeBSD_kernel__");	\
	builtin_define ("__GLIBC__");		\
	builtin_define_std ("unix");		\
	builtin_assert ("system=unix");		\
	builtin_assert ("system=posix");	\
    }						\
  while (0)

#define GNU_USER_DYNAMIC_LINKER        GLIBC_DYNAMIC_LINKER
#define GNU_USER_DYNAMIC_LINKER32      GLIBC_DYNAMIC_LINKER32
#define GNU_USER_DYNAMIC_LINKER64      GLIBC_DYNAMIC_LINKER64
#define GNU_USER_DYNAMIC_LINKERX32     GLIBC_DYNAMIC_LINKERX32
