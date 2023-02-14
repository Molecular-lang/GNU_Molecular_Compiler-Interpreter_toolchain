/* xexit.c -- Run any exit handlers, then exit. */

/*

@deftypefn Replacement void xexit (int @var{code})

Terminates the program.  If any functions have been registered with
the @code{xatexit} replacement function, they will be called first.
Termination is handled via the system's normal @code{exit} call.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <stdio.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include "libiberty.h"


/* This variable is set by xatexit if it is called.  This way, xmalloc
   doesn't drag xatexit into the link.  */
void (*_xexit_cleanup) (void);

void
xexit (int code)
{
  if (_xexit_cleanup != NULL)
    (*_xexit_cleanup) ();
  exit (code);
}
