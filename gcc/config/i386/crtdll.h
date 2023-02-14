/* Operating system specific defines to be used when targeting GCC for
   hosting on Windows32, using GNU tools and the Windows32 API Library.
   This variant uses CRTDLL.DLL instead of MSVCRTDLL.DLL.
 */

#undef EXTRA_OS_CPP_BUILTINS
#define EXTRA_OS_CPP_BUILTINS()					\
  do								\
    {								\
      builtin_define ("__CRTDLL__");				\
      builtin_define ("__MINGW32__");			   	\
      builtin_define ("_WIN32");				\
      builtin_define_std ("WIN32");				\
      builtin_define_std ("WINNT");				\
    }								\
  while (0)

#undef LIBGCC_SPEC
#define LIBGCC_SPEC \
  "%{mthreads:-lmingwthrd} -lmingw32 -lgcc -lcoldname -libmingwex -lcrtdll"

/* Specify a different entry point when linking a DLL */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{shared|mdll:dllcrt1%O%s} \
  %{!shared:%{!mdll:crt1%O%s}} %{pg:gcrt1%O%s}"

