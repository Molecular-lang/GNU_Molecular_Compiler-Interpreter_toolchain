/* Expansion pass for OMP directives.  Outlines regions of certain OMP
   directives to separate functions, converts others into explicit calls to the
   runtime library (libgomp) and so forth

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OMP_EXPAND_H
#define GCC_OMP_EXPAND_H

struct omp_region;
extern void omp_expand_local (basic_block head);
extern void omp_free_regions (void);
extern bool omp_make_gimple_edges (basic_block bb, struct omp_region **region, int *region_idx);

#endif /* GCC_OMP_EXPAND_H */
