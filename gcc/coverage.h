/* coverage.h - Defines data exported from coverage.cc
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_COVERAGE_H
#define GCC_COVERAGE_H

#include "gcov-io.h"

extern void coverage_init (const char *);
extern void coverage_finish (void);
extern void coverage_remove_note_file (void);

/* Start outputting coverage information for the current
   function.  */
extern int coverage_begin_function (unsigned, unsigned);

/* Complete the coverage information for the current function.  */
extern void coverage_end_function (unsigned, unsigned);

/* Compute the control flow checksum for the function FN given as argument.  */
extern unsigned coverage_compute_cfg_checksum (struct function *fn);

/* Compute the profile id of function N.  */
extern unsigned coverage_compute_profile_id (struct cgraph_node *n);

/* Compute the line number checksum for the current function.  */
extern unsigned coverage_compute_lineno_checksum (void);

/* Allocate some counters. Repeatable per function.  */
extern int coverage_counter_alloc (unsigned /*counter*/, unsigned/*num*/);
/* Use a counter from the most recent allocation.  */
extern tree tree_coverage_counter_ref (unsigned /*counter*/, unsigned/*num*/);
/* Use a counter address from the most recent allocation.  */
extern tree tree_coverage_counter_addr (unsigned /*counter*/, unsigned/*num*/);

/* Get all the counters for the current function.  */
extern gcov_type *get_coverage_counts (unsigned /*counter*/,
				       unsigned /*cfg_checksum*/,
				       unsigned /*lineno_checksum*/,
				       unsigned /*n_counts*/);

extern tree get_gcov_type (void);
extern bool coverage_node_map_initialized_p (void);

#endif
