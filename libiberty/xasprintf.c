/* Implement the xasprintf function. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "ansidecl.h"
#include "libiberty.h"

#include <stdarg.h>

/*

@deftypefn Replacement char* xasprintf (const char *@var{format}, ...)

Print to allocated string without fail.  If @code{xasprintf} fails,
this will print a message to @code{stderr} (using the name set by
@code{xmalloc_set_program_name}, if any) and then call @code{xexit}.

@end deftypefn

*/

char *
xasprintf (const char *fmt, ...)
{
  char *buf;
  va_list ap;
  va_start (ap, fmt);
  buf = xvasprintf (fmt, ap);
  va_end (ap);
  return buf;
}
