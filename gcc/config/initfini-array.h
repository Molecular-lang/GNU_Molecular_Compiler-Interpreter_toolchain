/* Definitions for ELF systems with .init_array/.fini_array section
   support.
 */

#if HAVE_INITFINI_ARRAY_SUPPORT

#define USE_INITFINI_ARRAY

#undef INIT_SECTION_ASM_OP
#undef FINI_SECTION_ASM_OP

#undef INIT_ARRAY_SECTION_ASM_OP
#define INIT_ARRAY_SECTION_ASM_OP

#undef FINI_ARRAY_SECTION_ASM_OP
#define FINI_ARRAY_SECTION_ASM_OP

/* Use .init_array/.fini_array section for constructors and destructors. */
#undef TARGET_ASM_CONSTRUCTOR
#define TARGET_ASM_CONSTRUCTOR default_elf_init_array_asm_out_constructor
#undef TARGET_ASM_DESTRUCTOR
#define TARGET_ASM_DESTRUCTOR default_elf_fini_array_asm_out_destructor

#endif
