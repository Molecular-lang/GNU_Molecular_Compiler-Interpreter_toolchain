/* Definitions for RDOS on i386.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* RDOS uses .exe suffix */
#undef TARGET_EXECUTABLE_SUFFIX
#define TARGET_EXECUTABLE_SUFFIX ".exe"

#undef TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
#define TARGET_TLS_DIRECT_SEG_REFS_DEFAULT MASK_TLS_DIRECT_SEG_REFS

#undef DEFAULT_TLS_SEG_REG
#define DEFAULT_TLS_SEG_REG ADDR_SPACE_SEG_GS

#undef TARGET_RDOS
#define TARGET_RDOS 1

#define TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
      builtin_define ("__RDOS__");		\
      builtin_assert ("system=rdos");		\
    }						\
  while (0)
