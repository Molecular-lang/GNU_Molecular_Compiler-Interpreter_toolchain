/* Find near-matches for identifiers.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "cpplib.h"
#include "spellcheck-tree.h"
#include "selftest.h"
#include "stringpool.h"

/* Calculate edit distance between two identifiers.  */

edit_distance_t
get_edit_distance (tree ident_s, tree ident_t)
{
  gcc_assert (TREE_CODE (ident_s) == IDENTIFIER_NODE);
  gcc_assert (TREE_CODE (ident_t) == IDENTIFIER_NODE);

  return get_edit_distance (IDENTIFIER_POINTER (ident_s),
			    IDENTIFIER_LENGTH (ident_s),
			    IDENTIFIER_POINTER (ident_t),
			    IDENTIFIER_LENGTH (ident_t));
}

/* Given TARGET, an identifier, and CANDIDATES, a vec of identifiers,
   determine which element within CANDIDATES has the lowest edit
   distance to TARGET.  If there are multiple elements with the
   same minimal distance, the first in the vector wins.

   If more than half of the letters were misspelled, the suggestion is
   likely to be meaningless, so return NULL_TREE for this case.  */

tree
find_closest_identifier (tree target, const auto_vec<tree> *candidates)
{
  gcc_assert (TREE_CODE (target) == IDENTIFIER_NODE);

  best_match<tree, tree> bm (target);
  int i;
  tree identifier;
  FOR_EACH_VEC_ELT (*candidates, i, identifier)
    {
      gcc_assert (TREE_CODE (identifier) == IDENTIFIER_NODE);
      bm.consider (identifier);
    }

  return bm.get_best_meaningful_candidate ();
}

#if CHECKING_P

namespace selftest {

/* Selftests.  */

/* Verify that find_closest_identifier is sane.  */

static void
test_find_closest_identifier ()
{
  auto_vec<tree> candidates;

  /* Verify that it can handle an empty vec.  */
  ASSERT_EQ (NULL, find_closest_identifier (get_identifier (""), &candidates));

  /* Verify that it works sanely for non-empty vecs.  */
  tree apple = get_identifier ("apple");
  tree banana = get_identifier ("banana");
  tree cherry = get_identifier ("cherry");
  candidates.safe_push (apple);
  candidates.safe_push (banana);
  candidates.safe_push (cherry);

  ASSERT_EQ (apple, find_closest_identifier (get_identifier ("app"),
					     &candidates));
  ASSERT_EQ (banana, find_closest_identifier (get_identifier ("banyan"),
					      &candidates));
  ASSERT_EQ (cherry, find_closest_identifier (get_identifier ("berry"),
					      &candidates));
  ASSERT_EQ (NULL,
	     find_closest_identifier (get_identifier ("not like the others"),
				      &candidates));
}

/* Run all of the selftests within this file.  */

void
spellcheck_tree_cc_tests ()
{
  test_find_closest_identifier ();
}

} // namespace selftest

#endif /* #if CHECKING_P */
