/* Header file for Induction variable optimizations.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_LOOP_IVOPTS_H
#define GCC_TREE_SSA_LOOP_IVOPTS_H

extern edge single_dom_exit (class loop *);
extern void dump_iv (FILE *, struct iv *);
extern void dump_use (FILE *, struct iv_use *);
extern void dump_uses (FILE *, struct ivopts_data *);
extern void dump_cand (FILE *, struct iv_cand *);
extern bool contains_abnormal_ssa_name_p (tree);
extern class loop *outermost_invariant_loop_for_expr (class loop *, tree);
extern bool expr_invariant_in_loop_p (class loop *, tree);
extern tree strip_offset (tree, poly_uint64_pod *);
bool may_be_nonaddressable_p (tree expr);
void tree_ssa_iv_optimize (void);

void create_canonical_iv (class loop *, edge, tree, tree * = NULL, tree * = NULL);
#endif /* GCC_TREE_SSA_LOOP_IVOPTS_H */
