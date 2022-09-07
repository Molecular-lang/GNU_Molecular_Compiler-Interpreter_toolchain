/* A class for building vector tree constants.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "fold-const.h"
#include "tree-vector-builder.h"

/* Return a vector element with the value BASE + FACTOR * STEP.  */

tree
tree_vector_builder::apply_step (tree base, unsigned int factor, const wide_int &step) const
{
  return wide_int_to_tree (TREE_TYPE (base),
			   wi::to_wide (base) + factor * step);
}

/* Return a VECTOR_CST for the current constant.  */

tree
tree_vector_builder::build ()
{
  finalize ();
  gcc_assert (pow2p_hwi (npatterns ()));
  tree v = make_vector (exact_log2 (npatterns ()), nelts_per_pattern ());
  TREE_TYPE (v) = m_type;
  memcpy (VECTOR_CST_ENCODED_ELTS (v), address (),
	  encoded_nelts () * sizeof (tree));
  return v;
}
