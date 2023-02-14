/* Base configuration file for all Fuchsia targets. */

/* Common Fuchsia configuration.  */

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared: crt1%O%s} crtbegin%O%s"

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC "crtend%O%s"

/* When neither pic nor pie has been specified, use PIE.  */
#undef  CC1_SPEC
#define CC1_SPEC "%{!fno-pic:%{!fno-PIC:%{!fpic:%{!fPIC:" \
                   "%{!fno-pie:%{!fno-PIE:%{!fpie:%{!fPIE: -fPIE}}}}}}}}"

#undef  LIB_SPEC
#define LIB_SPEC "--start-group" \
		 " -lmxio -lmagenta -lc -llaunchpad" \
		 "%{!static: -lgcc_s}" \
		 " --end-group"

#undef  LINK_SPEC
#define LINK_SPEC "-z max-page-size=4096" \
		  " -z combreloc" \
		  " -z relro" \
		  " -z now" \
		  " -z text" \
		  "%{!hash-style: --hash-style=gnu}" \
		  "%{!no-eh-frame-hdr: --eh-frame-hdr}" \
		  "%{!no-build-id: --build-id}" \
		  "%{shared: -shared}" \
		  "%{!shared:%{!static:%{!dynamic-linker: -dynamic-linker=ld.so.1}}}"

/* We are using MUSL as our libc.  */
#undef  OPTION_MUSL
#define OPTION_MUSL 1
#undef  OPTION_MUSL_P
#define OPTION_MUSL_P(opts) 1

#ifndef TARGET_SUB_OS_CPP_BUILTINS
#define TARGET_SUB_OS_CPP_BUILTINS()
#endif

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()		\
  do						\
    {						\
      builtin_define ("__fuchsia__");		\
      TARGET_SUB_OS_CPP_BUILTINS();		\
    }						\
  while (false)

