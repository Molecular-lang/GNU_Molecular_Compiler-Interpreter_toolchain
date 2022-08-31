/* Support routines for Value Range Propagation (VRP).
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_VRP_H
#define GCC_TREE_VRP_H

#include "value-range.h"

struct assert_info
{
  /* Predicate code for the ASSERT_EXPR.  Must be COMPARISON_CLASS_P.  */
  enum tree_code comp_code;

  /* Name to register the assert for.  */
  tree name;

  /* Value being compared against.  */
  tree val;

  /* Expression to compare.  */
  tree expr;
};

extern void register_edge_assert_for (tree, edge, enum tree_code,
				      tree, tree, vec<assert_info> &);
extern bool stmt_interesting_for_vrp (gimple *);
extern bool infer_value_range (gimple *, tree, tree_code *, tree *);

extern bool range_int_cst_p (const value_range *);

extern int compare_values (tree, tree);
extern int compare_values_warnv (tree, tree, bool *);
extern int operand_less_p (tree, tree);

void range_fold_unary_expr (value_range *, enum tree_code, tree type,
			    const value_range *, tree op0_type);
void range_fold_binary_expr (value_range *, enum tree_code, tree type,
			     const value_range *, const value_range *);

extern enum value_range_kind intersect_range_with_nonzero_bits
  (enum value_range_kind, wide_int *, wide_int *, const wide_int &, signop);

extern bool find_case_label_range (gswitch *, tree, tree, size_t *, size_t *);
extern tree find_case_label_range (gswitch *, const irange *vr);
extern bool find_case_label_index (gswitch *, size_t, tree, size_t *);
extern bool overflow_comparison_p (tree_code, tree, tree, bool, tree *);
extern tree get_single_symbol (tree, bool *, tree *);
extern void maybe_set_nonzero_bits (edge, tree);
extern wide_int masked_increment (const wide_int &val_in, const wide_int &mask,
				  const wide_int &sgnbit, unsigned int prec);

extern unsigned int execute_ranger_vrp (struct function *fun,
					bool warn_array_bounds_p = false);
#endif /* GCC_TREE_VRP_H */
