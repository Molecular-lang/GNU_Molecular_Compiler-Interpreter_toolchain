/* Allocate memory region filled with spaces. */

/*

@deftypefn Extension char* spaces (int @var{count})

Returns a pointer to a memory region filled with the specified
number of spaces and null terminated.  The returned pointer is
valid until at least the next call.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "ansidecl.h"
#include "libiberty.h"

#if VMS
#include <stdlib.h>
#include <unixlib.h>
#else
/* For systems with larger pointers than ints, these must be declared.  */
extern void *malloc (size_t);
extern void free (void *);
#endif

const char *
spaces (int count)
{
  register char *t;
  static char *buf;
  static int maxsize;

  if (count > maxsize)
    {
      free (buf);
      buf = (char *) malloc (count + 1);
      if (buf == (char *) 0)
	return 0;
      for (t = buf + count ; t != buf ; )
	{
	  *--t = ' ';
	}
      maxsize = count;
      buf[count] = '\0';
    }
  return (const char *) (buf + maxsize - count);
}

