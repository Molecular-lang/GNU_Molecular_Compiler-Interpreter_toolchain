/* Support routines for dead store elimination. 
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_SSA_DSE_H
#define GCC_TREE_SSA_DSE_H

/* Return value from dse_classify_store */
enum dse_store_status
{
  DSE_STORE_LIVE,
  DSE_STORE_MAYBE_PARTIAL_DEAD,
  DSE_STORE_DEAD
};

dse_store_status dse_classify_store (ao_ref *, gimple *, bool, sbitmap, bool * = NULL, tree = NULL);

void delete_dead_or_redundant_assignment (gimple_stmt_iterator *, const char *, bitmap = NULL, bitmap = NULL);

#endif   /* GCC_TREE_SSA_DSE_H  */
