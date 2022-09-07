/* Target definitions for GCC for Intel 80386 using ELF
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Define DEFAULT_PCC_STRUCT_RETURN to 1 because the i386 SVR4 ABI returns
   records and unions in memory. ix86_option_override_internal will overide
   this flag when compiling 64-bit code as we never do pcc_struct_return
   scheme on x86-64.  */
#undef DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 1

#undef CPP_SPEC
#define CPP_SPEC ""

#define ENDFILE_SPEC "crtend.o%s"

#define STARTFILE_SPEC "%{!shared: \
			 %{!symbolic: \
			  %{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}}\
			crtbegin.o%s"

#undef DBX_REGISTER_NUMBER
#define DBX_REGISTER_NUMBER(n) \
  (TARGET_64BIT ? dbx64_register_map[n] : svr4_dbx_register_map[n])

#define LOCAL_LABEL_PREFIX	"."

/* Switch into a generic section.  */
#define TARGET_ASM_NAMED_SECTION  default_elf_asm_named_section

#undef BSS_SECTION_ASM_OP
#define BSS_SECTION_ASM_OP "\t.section\t.bss"

#undef ASM_OUTPUT_ALIGNED_BSS
#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN) \
  asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
