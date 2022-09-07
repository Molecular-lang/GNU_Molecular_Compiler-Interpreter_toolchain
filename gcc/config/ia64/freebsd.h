/* Definitions for Intel IA-64 running FreeBSD using the ELF format
   Please review: $(src-dir)/SPL-README for Licencing info. */

#undef  SUBTARGET_EXTRA_SPECS
#define SUBTARGET_EXTRA_SPECS \
  { "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }

#define LINK_SPEC "							\
  %{p:%nconsider using '-pg' instead of '-p' with gprof(1)}		\
  %{assert*} %{R*} %{rpath*} %{defsym*}					\
  %{shared:-Bshareable %{h*} %{soname*}}				\
  %{symbolic:-Bsymbolic}						\
  %{!shared:								\
    %{!static:								\
      %{rdynamic:-export-dynamic}					\
      -dynamic-linker %(fbsd_dynamic_linker) }	\
    %{static:-Bstatic}}"


/************************[  Target stuff  ]***********************************/

/* Define the actual types of some ANSI-mandated types.  
   Needs to agree with <machine/ansi.h>.  GCC defaults come from c-decl.cc,
   c-common.cc, and config/<arch>/<arch>.h.  */

/* Earlier headers may get this wrong for FreeBSD.
   We use the GCC defaults instead.  */
#undef WCHAR_TYPE

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 32

#define TARGET_ELF		1

#define JMP_BUF_SIZE  76
