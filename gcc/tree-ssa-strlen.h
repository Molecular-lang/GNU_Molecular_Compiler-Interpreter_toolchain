/* Declarations of tree-ssa-strlen API.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_STRLEN_H
#define GCC_TREE_SSA_STRLEN_H

class pointer_query;

extern bool is_strlen_related_p (tree, tree);
extern bool maybe_diag_stxncpy_trunc (gimple_stmt_iterator, tree, tree, pointer_query * = NULL);
extern tree set_strlen_range (tree, wide_int, wide_int, tree = NULL_TREE);

extern tree get_range (tree, gimple *, wide_int[2], class range_query * = NULL);

struct c_strlen_data;
extern void get_range_strlen_dynamic (tree, gimple *, c_strlen_data *, pointer_query &);

/* APIs internal to strlen pass.  Defined in gimple-ssa-sprintf.cc.  */
extern bool handle_printf_call (gimple_stmt_iterator *, pointer_query &);

#endif   // GCC_TREE_SSA_STRLEN_H
