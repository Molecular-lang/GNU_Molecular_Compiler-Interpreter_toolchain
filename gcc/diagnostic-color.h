/* Please review: $(src-dir)/SPL-README for Licencing info. */

/* Based on code from: */
/* grep.c - main driver file for grep. */

#ifndef GCC_DIAGNOSTIC_COLOR_H
#define GCC_DIAGNOSTIC_COLOR_H

/* Whether to add color to diagnostics:
   o DIAGNOSTICS_COLOR_NO: never
   o DIAGNOSTICS_COLOR_YES: always
   o DIAGNOSTICS_COLOR_AUTO: depending on the output stream.  */
typedef enum
{
  DIAGNOSTICS_COLOR_NO       = 0,
  DIAGNOSTICS_COLOR_YES      = 1,
  DIAGNOSTICS_COLOR_AUTO     = 2
} diagnostic_color_rule_t;

const char *colorize_start (bool, const char *, size_t);
const char *colorize_stop (bool);
bool colorize_init (diagnostic_color_rule_t);

inline const char *
colorize_start (bool show_color, const char *name)
{
  return colorize_start (show_color, name, strlen (name));
}

#endif /* ! GCC_DIAGNOSTIC_COLOR_H */
