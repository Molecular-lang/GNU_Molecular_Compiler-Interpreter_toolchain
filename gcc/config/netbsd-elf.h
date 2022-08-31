/* Common configuration file for NetBSD ELF targets.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* TARGET_OS_CPP_BUILTINS() common to all NetBSD ELF targets.  */
#define NETBSD_OS_CPP_BUILTINS_ELF()		\
  do						\
    {						\
      NETBSD_OS_CPP_BUILTINS_COMMON();		\
    }						\
  while (0)

/* Provide a STARTFILE_SPEC appropriate for NetBSD ELF.  Here we
   provide support for the special GCC option -static.  On ELF
   targets, we also add the crtbegin.o file, which provides part
   of the support for getting C++ file-scope static objects
   constructed before entering "main".  */

#define NETBSD_STARTFILE_SPEC	\
  "%{!shared:			\
     %{pg:gcrt0%O%s}		\
     %{!pg:			\
       %{p:gcrt0%O%s}		\
       %{!p:crt0%O%s}}}		\
   %:if-exists(crti%O%s)	\
   %{static:%:if-exists-else(crtbeginT%O%s crtbegin%O%s)} \
   %{!static:                   \
     %{!shared:                 \
       %{!pie:crtbegin%O%s}     \
       %{pie:crtbeginS%O%s}}    \
     %{shared:crtbeginS%O%s}}"

#undef STARTFILE_SPEC
#define STARTFILE_SPEC NETBSD_STARTFILE_SPEC


/* Provide an ENDFILE_SPEC appropriate for NetBSD ELF.  Here we
   add crtend.o, which provides part of the support for getting
   C++ file-scope static objects deconstructed after exiting "main".  */

#define NETBSD_ENDFILE_SPEC	\
  "%{!shared:                   \
    %{!pie:crtend%O%s}          \
    %{pie:crtendS%O%s}}         \
   %{shared:crtendS%O%s}        \
   %:if-exists(crtn%O%s)"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC NETBSD_ENDFILE_SPEC

/* Provide a LINK_SPEC appropriate for NetBSD ELF.  Here we provide
   support for the special GCC options -assert, -R, -rpath, -shared,
   -nostdlib, -static, -rdynamic, and -dynamic-linker.

   Target-specific code can use this in conjunction with any other
   target-specific LINK_SPEC options.

   Target-specific code must provide the %(netbsd_entry_point) spec.  */

#define NETBSD_LINK_LD_ELF_SO_SPEC \
  "%{!dynamic-linker:-dynamic-linker /usr/libexec/ld.elf_so}"

#define NETBSD_LINK_SPEC_ELF \
  "%{assert*} %{R*} %{rpath*} \
   %{shared:-shared} \
   %{symbolic:-Bsymbolic} \
   %{!shared: \
     -dc -dp \
     %{!nostdlib: \
       %{!r: \
	 %{!e*:-e %(netbsd_entry_point)}}} \
     %{!static: \
       %{rdynamic:-export-dynamic} \
       -dynamic-linker /usr/libexec/ld.elf_so} \
     %{static:-static}}"

/* Provide the standard list of subtarget extra specs for NetBSD targets.  */
#define NETBSD_SUBTARGET_EXTRA_SPECS \
  { "netbsd_link_ld_elf_so",    NETBSD_LINK_LD_ELF_SO_SPEC }, \
  { "netbsd_cpp_spec",          NETBSD_CPP_SPEC }, \
  { "netbsd_link_spec",         NETBSD_LINK_SPEC_ELF }, \
  { "netbsd_entry_point",       NETBSD_ENTRY_POINT }, \
  { "netbsd_endfile_spec",      NETBSD_ENDFILE_SPEC },

#undef SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS   NETBSD_SUBTARGET_EXTRA_SPECS

/* Use --as-needed -lgcc_s for eh support.  */
#ifdef HAVE_LD_AS_NEEDED
#define USE_LD_AS_NEEDED 1
#endif
