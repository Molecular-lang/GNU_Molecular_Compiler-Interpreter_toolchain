/* Selftest support for the analyzer.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "stringpool.h"
#include "function.h"
#include "analyzer/analyzer.h"
#include "analyzer/analyzer-selftests.h"

#if CHECKING_P

namespace ana {

namespace selftest {

/* Build a VAR_DECL named NAME of type TYPE, simulating a file-level
   static variable.  */

tree
build_global_decl (const char *name, tree type)
{
  tree decl = build_decl (UNKNOWN_LOCATION, VAR_DECL,
			  get_identifier (name), type);
  TREE_STATIC (decl) = 1;
  return decl;
}

/* Run all analyzer-specific selftests.  */

void
run_analyzer_selftests ()
{
#if ENABLE_ANALYZER
  analyzer_constraint_manager_cc_tests ();
  analyzer_function_set_cc_tests ();
  analyzer_program_point_cc_tests ();
  analyzer_program_state_cc_tests ();
  analyzer_region_model_cc_tests ();
  analyzer_sm_file_cc_tests ();
  analyzer_sm_signal_cc_tests ();
  analyzer_store_cc_tests ();
#endif /* #if ENABLE_ANALYZER */
}

} /* end of namespace selftest.  */

} // namespace ana

#endif /* #if CHECKING_P */
