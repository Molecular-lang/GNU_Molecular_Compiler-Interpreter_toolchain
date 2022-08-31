/* Find near-matches for macros.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef C_SPELLCHECK_H
#define C_SPELLCHECK_H

#include "spellcheck.h"

extern bool name_reserved_for_implementation_p (const char *str);

/* Specialization of edit_distance_traits for preprocessor macros.  */

template <>
struct edit_distance_traits<cpp_hashnode *>
{
  static size_t get_length (cpp_hashnode *hashnode)
  {
    return hashnode->ident.len;
  }

  static const char *get_string (cpp_hashnode *hashnode)
  {
    return (const char *)hashnode->ident.str;
  }
};

/* Specialization of best_match<> for finding the closest preprocessor
   macro to a given identifier.  */

class best_macro_match : public best_match<tree, cpp_hashnode *>
{
 public:
  best_macro_match (tree goal, edit_distance_t best_distance_so_far,
		    cpp_reader *reader);
};

#endif  /* C_SPELLCHECK_H  */
