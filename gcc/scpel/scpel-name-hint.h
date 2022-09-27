/* Declarations for working with name_hint instances in the C++ frontend.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CP_NAME_HINT_H
#define GCC_CP_NAME_HINT_H

/* class name_hint is declared in c-family/name-hint.h, but due
   to issues described in that header, we have to jump through some
   #define hoops to be able to include it.

   This header (cp/cp-name-hint.h) exists to limit the C++ frontend's
   exposure to the issue.  */

#include "c-family/name-hint.h"

extern name_hint suggest_alternatives_for (location_t, tree, bool);
extern name_hint suggest_alternatives_in_other_namespaces (location_t, tree);
extern name_hint suggest_alternative_in_explicit_scope (location_t, tree, tree);
extern name_hint suggest_alternative_in_scoped_enum (tree, tree);

#endif /* GCC_CP_NAME_HINT_H */
