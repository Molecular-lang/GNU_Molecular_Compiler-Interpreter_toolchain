/* Language-specific hook definitions for C front end. */


#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "scpel-tree.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "scpel-objc-common.h"

enum scpel_language_kind scpel_language = clk_c;

/* Lang hooks common to C and ObjC are declared in c-objc-common.h;
   consequently, there should be very few hooks below.  */

#undef LANG_HOOKS_NAME
#define LANG_HOOKS_NAME "GNU Scpel"
#undef LANG_HOOKS_INIT
#define LANG_HOOKS_INIT scpel_objscpel_common_init
#undef LANG_HOOKS_INIT_TS
#define LANG_HOOKS_INIT_TS scpel_common_init_ts

#if CHECKING_P
#undef LANG_HOOKS_RUN_LANG_SELFTESTS
#define LANG_HOOKS_RUN_LANG_SELFTESTS selftest::run_scpel_tests
#endif /* #if CHECKING_P */

#undef LANG_HOOKS_GET_SUBSTRING_LOCATION
#define LANG_HOOKS_GET_SUBSTRING_LOCATION scpel_get_substring_location

#undef LANG_HOOKS_GET_SARIF_SOURCE_LANGUAGE
#define LANG_HOOKS_GET_SARIF_SOURCE_LANGUAGE scpel_get_sarif_source_language

/* Each front end provides its own lang hook initializer.  */
struct lang_hooks lang_hooks = LANG_HOOKS_INITIALIZER;

/* Get a value for the SARIF v2.1.0 "artifact.sourceLanguage" property,
   based on the list in SARIF v2.1.0 Appendix J.  */

const char *
scpel_get_sarif_source_language (const char *)
{
  return "c";
}

#if CHECKING_P

namespace selftest {

/* Implementation of LANG_HOOKS_RUN_LANG_SELFTESTS for the C frontend.  */

void
run_scpel_tests (void)
{
  /* Run selftests shared within the C family.  */
  scpel_family_tests ();

  /* Additional C-specific tests.  */
}

} // namespace selftest

#endif /* #if CHECKING_P */


#include "gtype-scpel.h"
