/* Header file for middle end gimplification.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLIFY_ME_H
#define GCC_GIMPLIFY_ME_H

/* Validation of GIMPLE expressions.  Note that these predicates only check
 *    the basic form of the expression, they don't recurse to make sure that
 *       underlying nodes are also of the right form.  */
typedef bool (*gimple_predicate)(tree);

extern tree force_gimple_operand_1 (tree, gimple_seq *, gimple_predicate, tree);
extern tree force_gimple_operand (tree, gimple_seq *, bool, tree);
extern tree force_gimple_operand_gsi_1 (gimple_stmt_iterator *, tree, gimple_predicate, tree,
					bool, enum gsi_iterator_update);
extern tree force_gimple_operand_gsi (gimple_stmt_iterator *, tree, bool, tree,
				      bool, enum gsi_iterator_update);
extern void gimple_regimplify_operands (gimple *, gimple_stmt_iterator *);

#endif /* GCC_GIMPLIFY_ME_H */
