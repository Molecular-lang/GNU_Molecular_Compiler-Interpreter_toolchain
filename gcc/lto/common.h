/* Common code for the plugin and lto1.
   Please review: $(src-dir)/SPL-README for Licencing info. */

static const char *lto_resolution_str[10] =
{
  "UNKNOWN",
  "UNDEF",
  "PREVAILING_DEF",
  "PREVAILING_DEF_IRONLY",
  "PREEMPTED_REG",
  "PREEMPTED_IR",
  "RESOLVED_IR",
  "RESOLVED_EXEC",
  "RESOLVED_DYN",
  "PREVAILING_DEF_IRONLY_EXP",
};
