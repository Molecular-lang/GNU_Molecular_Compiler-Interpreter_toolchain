/* Find near-matches for identifiers.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_SPELLCHECK_TREE_H
#define GCC_SPELLCHECK_TREE_H

#include "spellcheck.h"

/* spellcheck-tree.cc  */

extern edit_distance_t
get_edit_distance (tree ident_s, tree ident_t);

extern tree
find_closest_identifier (tree target, const auto_vec<tree> *candidates);

/* Specialization of edit_distance_traits for identifiers.  */

template <>
struct edit_distance_traits<tree>
{
  static size_t get_length (tree id)
  {
    gcc_assert (TREE_CODE (id) == IDENTIFIER_NODE);
    return IDENTIFIER_LENGTH (id);
  }

  static const char *get_string (tree id)
  {
    gcc_assert (TREE_CODE (id) == IDENTIFIER_NODE);
    return IDENTIFIER_POINTER (id);
  }
};

#endif  /* GCC_SPELLCHECK_TREE_H  */
