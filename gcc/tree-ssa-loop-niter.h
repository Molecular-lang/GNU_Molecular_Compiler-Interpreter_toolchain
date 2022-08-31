/* Header file for loop interation estimates.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_LOOP_NITER_H
#define GCC_TREE_SSA_LOOP_NITER_H

extern tree expand_simple_operations (tree, tree = NULL);
extern tree simplify_using_initial_conditions (class loop *, tree);
extern bool loop_only_exit_p (const class loop *, basic_block *body, const_edge);
extern bool number_of_iterations_exit (class loop *, edge,
				       class tree_niter_desc *niter, bool,
				       bool every_iteration = true,
				       basic_block * = NULL);
extern bool number_of_iterations_exit_assumptions (class loop *, edge,
						   class tree_niter_desc *,
						   gcond **, bool = true,
						   basic_block * = NULL);
extern tree find_loop_niter (class loop *, edge *);
extern bool finite_loop_p (class loop *);
extern tree loop_niter_by_eval (class loop *, edge);
extern tree find_loop_niter_by_eval (class loop *, edge *);
extern bool estimated_loop_iterations (class loop *, widest_int *);
extern HOST_WIDE_INT estimated_loop_iterations_int (class loop *);
extern bool max_loop_iterations (class loop *, widest_int *);
extern HOST_WIDE_INT max_loop_iterations_int (class loop *);
extern bool likely_max_loop_iterations (class loop *, widest_int *);
extern HOST_WIDE_INT likely_max_loop_iterations_int (class loop *);
extern HOST_WIDE_INT max_stmt_executions_int (class loop *);
extern HOST_WIDE_INT likely_max_stmt_executions_int (class loop *);
extern HOST_WIDE_INT estimated_stmt_executions_int (class loop *);
extern bool max_stmt_executions (class loop *, widest_int *);
extern bool likely_max_stmt_executions (class loop *, widest_int *);
extern bool estimated_stmt_executions (class loop *, widest_int *);
extern void estimate_numbers_of_iterations (function *);
extern void estimate_numbers_of_iterations (class loop *);
extern bool stmt_dominates_stmt_p (gimple *, gimple *);
extern bool nowrap_type_p (tree);
extern bool scev_probably_wraps_p (tree, tree, tree, gimple *,
				   class loop *, bool);
extern void free_numbers_of_iterations_estimates (class loop *);
extern void free_numbers_of_iterations_estimates (function *);
extern tree simplify_replace_tree (tree, tree,
				   tree, tree (*)(tree, void *) = NULL,
				   void * = NULL, bool do_fold = true);
extern void substitute_in_loop_info (class loop *, tree, tree);

#endif /* GCC_TREE_SSA_LOOP_NITER_H */
