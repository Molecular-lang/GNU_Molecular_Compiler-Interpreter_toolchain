/* Definitions for rtems targeting an ix86 using ELF.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Specify predefined symbols in preprocessor.  */

#define TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
	builtin_define ("__rtems__");		\
	builtin_define ("__USE_INIT_FINI__");	\
	builtin_assert ("system=rtems");	\
    }						\
  while (0)
