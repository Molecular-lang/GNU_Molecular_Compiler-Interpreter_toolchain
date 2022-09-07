/* Header file for gimple lowering pass.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_LOW_H
#define GCC_GIMPLE_LOW_H

extern bool gimple_stmt_may_fallthru (gimple *);
extern bool gimple_seq_may_fallthru (gimple_seq);
extern void record_vars_into (tree, tree);
extern void record_vars (tree);

#endif /* GCC_GIMPLE_LOW_H */
