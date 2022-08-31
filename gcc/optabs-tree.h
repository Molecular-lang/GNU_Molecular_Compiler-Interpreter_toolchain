/* Tree-based target query functions relating to optabs
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OPTABS_TREE_H
#define GCC_OPTABS_TREE_H

#include "optabs-query.h"

/* An extra flag to control optab_for_tree_code's behavior.  This is needed to
   distinguish between machines with a vector shift that takes a scalar for the
   shift amount vs. machines that take a vector for the shift amount.  */
enum optab_subtype
{
  optab_default,
  optab_scalar,
  optab_vector,
  optab_vector_mixed_sign
};

/* Return the optab used for computing the given operation on the type given by
   the second argument.  The third argument distinguishes between the types of
   vector shifts and rotates.  */
optab optab_for_tree_code (enum tree_code, const_tree, enum optab_subtype);
bool
supportable_half_widening_operation (enum tree_code, tree, tree,
				    enum tree_code *);
bool supportable_convert_operation (enum tree_code, tree, tree,
				    enum tree_code *);
bool expand_vec_cmp_expr_p (tree, tree, enum tree_code);
bool expand_vec_cond_expr_p (tree, tree, enum tree_code);
void init_tree_optimization_optabs (tree);
bool target_supports_op_p (tree, enum tree_code,
			   enum optab_subtype = optab_default);

#endif
