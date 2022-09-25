/* Subclasses of logical_location with knowledge of "tree".
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "pretty-print.h"
#include "tree-logical-location.h"
#include "langhooks.h"

/* class compiler_logical_location : public logical_location.  */

/* Get a string for DECL suitable for use by the SARIF logicalLocation
   "name" property (SARIF v2.1.0 section 3.33.4).  */

const char *
compiler_logical_location::get_short_name_for_tree (tree decl)
{
  gcc_assert (decl);
  return identifier_to_locale (lang_hooks.decl_printable_name (decl, 0));
}

/* Get a string for DECL suitable for use by the SARIF logicalLocation
   "fullyQualifiedName" property (SARIF v2.1.0 section 3.33.5).  */

const char *
compiler_logical_location::get_name_with_scope_for_tree (tree decl)
{
  gcc_assert (decl);
  return identifier_to_locale (lang_hooks.decl_printable_name (decl, 1));
}

/* Get a string for DECL suitable for use by the SARIF logicalLocation
   "decoratedName" property (SARIF v2.1.0 section 3.33.6).  */

const char *
compiler_logical_location::get_internal_name_for_tree (tree decl)
{
  gcc_assert (decl);
  if (HAS_DECL_ASSEMBLER_NAME_P (decl))
    if (tree id = DECL_ASSEMBLER_NAME (decl))
      return IDENTIFIER_POINTER (id);
  return NULL;
}

/* Get what kind of SARIF logicalLocation DECL is (if any).  */

enum logical_location_kind
compiler_logical_location::get_kind_for_tree (tree decl)
{
  if (!decl)
    return LOGICAL_LOCATION_KIND_UNKNOWN;

  switch (TREE_CODE (decl))
    {
    default:
      return LOGICAL_LOCATION_KIND_UNKNOWN;
    case FUNCTION_DECL:
      return LOGICAL_LOCATION_KIND_FUNCTION;
    case PARM_DECL:
      return LOGICAL_LOCATION_KIND_PARAMETER;
    case VAR_DECL:
      return LOGICAL_LOCATION_KIND_VARIABLE;
    }
}

/* class tree_logical_location : public compiler_logical_location.  */

/* Implementation of the logical_location vfuncs, using m_decl.  */

const char *
tree_logical_location::get_short_name () const
{
  gcc_assert (m_decl);
  return get_short_name_for_tree (m_decl);
}

const char *
tree_logical_location::get_name_with_scope () const
{
  gcc_assert (m_decl);
  return get_name_with_scope_for_tree (m_decl);
}

const char *
tree_logical_location::get_internal_name () const
{
  gcc_assert (m_decl);
  return get_internal_name_for_tree (m_decl);
}

enum logical_location_kind
tree_logical_location::get_kind () const
{
  gcc_assert (m_decl);
  return get_kind_for_tree (m_decl);
}

/* class current_fndecl_logical_location : public compiler_logical_location.  */

/* Implementation of the logical_location vfuncs, using
   current_function_decl.  */

const char *
current_fndecl_logical_location::get_short_name () const
{
  gcc_assert (current_function_decl);
  return get_short_name_for_tree (current_function_decl);
}

const char *
current_fndecl_logical_location::get_name_with_scope () const
{
  gcc_assert (current_function_decl);
  return get_name_with_scope_for_tree (current_function_decl);
}

const char *
current_fndecl_logical_location::get_internal_name () const
{
  gcc_assert (current_function_decl);
  return get_internal_name_for_tree (current_function_decl);
}

enum logical_location_kind
current_fndecl_logical_location::get_kind () const
{
  gcc_assert (current_function_decl);
  return get_kind_for_tree (current_function_decl);
}
