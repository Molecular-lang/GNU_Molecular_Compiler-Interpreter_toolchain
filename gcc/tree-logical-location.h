/* Subclasses of logical_location with knowledge of "tree".
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_LOGICAL_LOCATION_H
#define GCC_TREE_LOGICAL_LOCATION_H

#include "logical-location.h"

/* Abstract subclass of logical_location, with knowledge of "tree", but
   for no specific tree.  */

class compiler_logical_location : public logical_location
{
 protected:
  static const char *get_short_name_for_tree (tree);
  static const char *get_name_with_scope_for_tree (tree);
  static const char *get_internal_name_for_tree (tree);
  static enum logical_location_kind get_kind_for_tree (tree);
};

/* Concrete subclass of logical_location, with reference to a specific
   tree.  */

class tree_logical_location : public compiler_logical_location
{
public:
  tree_logical_location (tree decl) : m_decl (decl) {}

  const char *get_short_name () const final override;
  const char *get_name_with_scope () const final override;
  const char *get_internal_name () const final override;
  enum logical_location_kind get_kind () const final override;

private:
  tree m_decl;
};

/* Concrete subclass of logical_location, with reference to
   current_function_decl.  */

class current_fndecl_logical_location : public compiler_logical_location
{
public:
  const char *get_short_name () const final override;
  const char *get_name_with_scope () const final override;
  const char *get_internal_name () const final override;
  enum logical_location_kind get_kind () const final override;
};

#endif /* GCC_TREE_LOGICAL_LOCATION_H.  */
