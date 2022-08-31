/* Header file for SSA dominator optimizations.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_DOM_H
#define GCC_TREE_SSA_DOM_H

extern bool simple_iv_increment_p (gimple *);
extern void record_temporary_equivalences (edge, class const_and_copies *, class avail_exprs_stack *);

#endif /* GCC_TREE_SSA_DOM_H */
