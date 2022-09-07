/* Header file for openMP lowering directives.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OMP_LOW_H
#define GCC_OMP_LOW_H

extern tree omp_reduction_init_op (location_t, enum tree_code, tree);
extern tree omp_reduction_init (tree, tree);
extern tree omp_member_access_dummy_var (tree);
extern tree omp_find_combined_for (gimple_stmt_iterator *gsi_p, bool *handled_ops_p, struct walk_stmt_info *wi);


#endif /* GCC_OMP_LOW_H */
