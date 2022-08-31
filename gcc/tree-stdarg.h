/* Header for a pass computing data for optimizing stdarg functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_STDARG_H
#define GCC_TREE_STDARG_H 1

struct stdarg_info {
  bitmap va_list_vars, va_list_escape_vars;
  basic_block bb;
  int compute_sizes, va_start_count;
  bool va_list_escapes;
  int *offsets;
  /* These 2 fields are only meaningful if va_start_count == 1.  */
  basic_block va_start_bb;
  tree va_start_ap;
};

#endif
