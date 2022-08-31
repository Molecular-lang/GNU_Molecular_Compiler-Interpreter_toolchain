/* Selftest support for diagnostics.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_SELFTEST_DIAGNOSTIC_H
#define GCC_SELFTEST_DIAGNOSTIC_H

/* The selftest code should entirely disappear in a production
   configuration, hence we guard all of it with #if CHECKING_P.  */

#if CHECKING_P

namespace selftest {

/* Convenience subclass of diagnostic_context for testing
   the diagnostic subsystem.  */

class test_diagnostic_context : public diagnostic_context
{
 public:
  test_diagnostic_context ();
  ~test_diagnostic_context ();

  /* Implementation of diagnostic_start_span_fn, hiding the
     real filename (to avoid printing the names of tempfiles).  */
  static void
  start_span_cb (diagnostic_context *context, expanded_location exploc);
};

} // namespace selftest

#endif /* #if CHECKING_P */

#endif /* GCC_SELFTEST_DIAGNOSTIC_H */
