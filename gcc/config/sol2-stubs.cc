/* Stubs for C++ specific Solaris system support.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"

/* Stub implemenation of TARGET_CXX_DECL_MANGLING_CONTEXT for non-C++
   frontends.  */
tree
solaris_cxx_decl_mangling_context (const_tree decl ATTRIBUTE_UNUSED)
{
  return NULL_TREE;
}
