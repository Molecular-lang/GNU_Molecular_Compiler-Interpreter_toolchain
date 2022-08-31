/* Generic simplify definitions.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GENERIC_MATCH_H
#define GCC_GENERIC_MATCH_H

/* Note the following functions are supposed to be only used from
   fold_unary_loc, fold_binary_loc and fold_ternary_loc respectively.
   They are not considered a public API.  */

tree generic_simplify (location_t, enum tree_code, tree, tree);
tree generic_simplify (location_t, enum tree_code, tree, tree, tree);
tree generic_simplify (location_t, enum tree_code, tree, tree, tree, tree);

#endif  /* GCC_GENERIC_MATCH_H */
