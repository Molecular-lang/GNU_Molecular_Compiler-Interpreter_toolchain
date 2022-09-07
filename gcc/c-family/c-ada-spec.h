/* Interface for -fdump-ada-spec capability.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef C_ADA_SPEC_H
#define C_ADA_SPEC_H

#include "pretty-print.h"

/* In c-ada-spec.cc  */

enum cpp_operation {
  HAS_DEPENDENT_TEMPLATE_ARGS,
  IS_ABSTRACT,
  IS_ASSIGNMENT_OPERATOR,
  IS_CONSTRUCTOR,
  IS_DESTRUCTOR,
  IS_COPY_CONSTRUCTOR,
  IS_MOVE_CONSTRUCTOR,
  IS_TEMPLATE,
  IS_TRIVIAL
};

extern void collect_ada_nodes (tree, const char *);
extern void collect_source_ref (const char *);
extern void dump_ada_specs (void (*)(const char *),
			    int (*)(tree, cpp_operation));

#endif /* ! C_ADA_SPEC_H */
