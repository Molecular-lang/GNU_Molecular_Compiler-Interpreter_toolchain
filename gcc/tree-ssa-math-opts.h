/* Global, SSA-based optimizations using mathematical identities.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_MATH_OPTS_H
#define GCC_TREE_SSA_MATH_OPTS_H

extern tree powi_as_mults (gimple_stmt_iterator *, location_t, tree, HOST_WIDE_INT);

#endif  /* GCC_TREE_SSA_MATH_OPTS_H  */
