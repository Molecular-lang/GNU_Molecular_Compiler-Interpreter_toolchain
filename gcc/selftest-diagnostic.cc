/* Selftest support for diagnostics.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "diagnostic.h"
#include "selftest.h"
#include "selftest-diagnostic.h"

/* The selftest code should entirely disappear in a production
   configuration, hence we guard all of it with #if CHECKING_P.  */

#if CHECKING_P

namespace selftest {

/* Implementation of class selftest::test_diagnostic_context.  */

test_diagnostic_context::test_diagnostic_context ()
{
  diagnostic_initialize (this, 0);
  show_caret = true;
  show_labels_p = true;
  show_column = true;
  start_span = start_span_cb;
  min_margin_width = 6;
}

test_diagnostic_context::~test_diagnostic_context ()
{
  diagnostic_finish (this);
}

/* Implementation of diagnostic_start_span_fn, hiding the
   real filename (to avoid printing the names of tempfiles).  */

void
test_diagnostic_context::start_span_cb (diagnostic_context *context,
					expanded_location exploc)
{
  exploc.file = "FILENAME";
  default_diagnostic_start_span_fn (context, exploc);
}

} // namespace selftest

#endif /* #if CHECKING_P */
