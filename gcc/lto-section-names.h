/* Definitions for LTO section names.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LTO_SECTION_NAMES_H
#define GCC_LTO_SECTION_NAMES_H

/* The string that is the prefix on the section names we make for lto.
   For decls the DECL_ASSEMBLER_NAME is appended to make the section
   name for the functions and static_initializers.  For other types of
   sections a '.' and the section type are appended.  */
#define LTO_SECTION_NAME_PREFIX ".gnu.lto_"
#define OFFLOAD_SECTION_NAME_PREFIX ".gnu.offload_lto_"

/* Can be either OFFLOAD_SECTION_NAME_PREFIX when we stream IR for offload
   compiler, or LTO_SECTION_NAME_PREFIX for LTO case.  */
extern const char *section_name_prefix;

/* Segment name for LTO sections.  This is only used for Mach-O.  */

#define LTO_SEGMENT_NAME "__GNU_LTO"

#define OFFLOAD_VAR_TABLE_SECTION_NAME ".gnu.offload_vars"
#define OFFLOAD_FUNC_TABLE_SECTION_NAME ".gnu.offload_funcs"

#endif /* GCC_LTO_SECTION_NAMES_H */
