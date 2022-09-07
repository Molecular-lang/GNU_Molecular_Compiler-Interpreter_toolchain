/* Header file for high level statement building routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */


#ifndef GCC_GIMPLE_BUILDER_H
#define GCC_GIMPLE_BUILDER_H

/* ???  This API is legacy and should not be used in new code.  */

gassign *build_assign (enum tree_code, tree, int, tree lhs = NULL_TREE);
gassign *build_assign (enum tree_code, gimple *, int, tree lhs = NULL_TREE);
gassign *build_assign (enum tree_code, tree, tree, tree lhs = NULL_TREE);
gassign *build_assign (enum tree_code, gimple *, tree, tree lhs = NULL_TREE);
gassign *build_assign (enum tree_code, tree, gimple *, tree lhs = NULL_TREE);
gassign *build_assign (enum tree_code, gimple *, gimple *, tree lhs = NULL_TREE);
gassign *build_type_cast (tree, tree, tree lhs = NULL_TREE);
gassign *build_type_cast (tree, gimple *, tree lhs = NULL_TREE);

#endif /* GCC_GIMPLE_BUILDER_H */
