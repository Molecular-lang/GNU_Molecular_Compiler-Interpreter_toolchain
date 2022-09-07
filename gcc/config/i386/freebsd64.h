/* Definitions for AMD x86-64 running FreeBSD with ELF format
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define SUBTARGET_EXTRA_SPECS \
  { "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }

#undef CC1_SPEC
#define CC1_SPEC "%(cc1_cpu) %{profile:-p}"

/* Provide a LINK_SPEC appropriate for the FreeBSD/x86-64 ELF target.
   This is a copy of LINK_SPEC from <i386/freebsd.h> tweaked for
   the x86-64 target.  */

#undef	LINK_SPEC
#define LINK_SPEC "\
  %{m32:-m elf_i386_fbsd}%{!m32:-m elf_x86_64_fbsd} \
  %{p:%nconsider using '-pg' instead of '-p' with gprof(1)} \
  %{v:-V} \
  %{assert*} %{R*} %{rpath*} %{defsym*} \
  %{shared:-Bshareable %{h*} %{soname*}} \
    %{!shared: \
      %{!static: \
        %{rdynamic:-export-dynamic} \
	-dynamic-linker %(fbsd_dynamic_linker) } \
    %{static:-Bstatic}} \
  %{symbolic:-Bsymbolic}"

#undef	MULTILIB_DEFAULTS
#define MULTILIB_DEFAULTS { "m64" }
