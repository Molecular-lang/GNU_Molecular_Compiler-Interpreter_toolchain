/* Implement the xstrndup function.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/*

@deftypefn Replacement char* xstrndup (const char *@var{s}, size_t @var{n})

Returns a pointer to a copy of @var{s} with at most @var{n} characters
without fail, using @code{xmalloc} to obtain memory.  The result is
always NUL terminated.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <sys/types.h>
#ifdef HAVE_STRING_H
#include <string.h>
#else
# ifdef HAVE_STRINGS_H
#  include <strings.h>
# endif
#endif
#include "ansidecl.h"
#include "libiberty.h"

char *
xstrndup (const char *s, size_t n)
{
  char *result;
  size_t len = strnlen (s, n);

  result = XNEWVEC (char, len + 1);

  result[len] = '\0';
  return (char *) memcpy (result, s, len);
}
