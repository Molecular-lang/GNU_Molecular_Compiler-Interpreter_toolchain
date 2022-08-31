/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DIAGNOSTIC_URL_H
#define GCC_DIAGNOSTIC_URL_H

/* Whether to add URLs to diagnostics:
   - DIAGNOSTICS_URL_NO: never
   - DIAGNOSTICS_URL_YES: always
   - DIAGNOSTICS_URL_AUTO: depending on the output stream.  */
typedef enum
{
  DIAGNOSTICS_URL_NO       = 0,
  DIAGNOSTICS_URL_YES      = 1,
  DIAGNOSTICS_URL_AUTO     = 2
} diagnostic_url_rule_t;

/* Tells whether URLs should be emitted, and, if so, how to
   terminate strings within the escape sequence.   */
enum diagnostic_url_format
{
  /* No URLs shall be emitted.  */
  URL_FORMAT_NONE,

  /* Use ST string termination.  */
  URL_FORMAT_ST,

  /* Use BEL string termination.  */
  URL_FORMAT_BEL
};

const diagnostic_url_format URL_FORMAT_DEFAULT = URL_FORMAT_BEL;

extern diagnostic_url_format determine_url_format (diagnostic_url_rule_t);

#endif /* ! GCC_DIAGNOSTIC_URL_H */
