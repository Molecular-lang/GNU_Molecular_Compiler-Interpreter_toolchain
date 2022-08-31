/* Data types used in the IL symbol table.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LTO_SYMTAB_H
#define GCC_LTO_SYMTAB_H

enum gcc_plugin_symbol_kind
  {
    GCCPK_DEF,
    GCCPK_WEAKDEF,
    GCCPK_UNDEF,
    GCCPK_WEAKUNDEF,
    GCCPK_COMMON
  };

enum gcc_plugin_symbol_visibility
  {
    GCCPV_DEFAULT,
    GCCPV_PROTECTED,
    GCCPV_INTERNAL,
    GCCPV_HIDDEN
  };

enum gcc_plugin_symbol_type
{
  GCCST_UNKNOWN,
  GCCST_FUNCTION,
  GCCST_VARIABLE
};

enum gcc_plugin_symbol_section_kind
{
  GCCSSK_DEFAULT,
  GCCSSK_BSS
};

#endif /* GCC_LTO_SYMTAB_H  */
