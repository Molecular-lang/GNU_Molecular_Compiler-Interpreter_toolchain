/* Header file for High-level loop manipulation functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_LOOP_MANIP_H
#define GCC_TREE_SSA_LOOP_MANIP_H

typedef void (*transform_callback)(class loop *, void *);

extern void create_iv (tree, tree, tree, class loop *, gimple_stmt_iterator *, bool, tree *, tree *);
extern void rewrite_into_loop_closed_ssa_1 (bitmap, unsigned, int, class loop *);
extern void rewrite_into_loop_closed_ssa (bitmap, unsigned);
extern void rewrite_virtuals_into_loop_closed_ssa (class loop *);
extern void verify_loop_closed_ssa (bool, class loop * = NULL);

static inline void
checking_verify_loop_closed_ssa (bool verify_ssa_p, class loop *loop = NULL)
{
  if (flag_checking)
    verify_loop_closed_ssa (verify_ssa_p, loop);
}

extern basic_block split_loop_exit_edge (edge, bool = false);
extern basic_block ip_end_pos (class loop *);
extern basic_block ip_normal_pos (class loop *);
extern void standard_iv_increment_position (class loop *, gimple_stmt_iterator *, bool *);
extern bool
gimple_duplicate_loop_body_to_header_edge (class loop *, edge, unsigned int, sbitmap, edge, vec<edge> *, int);
extern bool can_unroll_loop_p (class loop *loop, unsigned factor, class tree_niter_desc *niter);
extern gcov_type niter_for_unrolled_loop (class loop *, unsigned);
extern void tree_transform_and_unroll_loop (class loop *, unsigned,
					    tree_niter_desc *,
					    transform_callback, void *);
extern void tree_unroll_loop (class loop *, unsigned, tree_niter_desc *);
extern tree canonicalize_loop_ivs (class loop *, tree *, bool);
extern unsigned int loop_invariant_motion_in_fun (function *, bool);


#endif /* GCC_TREE_SSA_LOOP_MANIP_H */
