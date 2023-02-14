/* Fold calls to built-in and internal functions with constant arguments. */

#ifndef GCC_FOLD_CONST_CALL_H
#define GCC_FOLD_CONST_CALL_H

tree fold_const_call (combined_fn, tree, tree);
tree fold_const_call (combined_fn, tree, tree, tree);
tree fold_const_call (combined_fn, tree, tree, tree, tree);
tree build_cmp_result (tree type, int res);

#endif
