/* Utility to pick a temporary filename prefix. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>	/* May get P_tmpdir.  */
#include <sys/types.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "libiberty.h"

/* Name of temporary file.
   mktemp requires 6 trailing X's.  */
#define TEMP_FILE "ccXXXXXX"
#define TEMP_FILE_LEN (sizeof(TEMP_FILE) - 1)

/*

@deftypefn Extension char* choose_temp_base (void)

Return a prefix for temporary file names or @code{NULL} if unable to
find one.  The current directory is chosen if all else fails so the
program is exited if a temporary directory can't be found (@code{mktemp}
fails).  The buffer for the result is obtained with @code{xmalloc}.

This function is provided for backwards compatibility only.  Its use is
not recommended.

@end deftypefn

*/

char *
choose_temp_base (void)
{
  const char *base = choose_tmpdir ();
  char *temp_filename;
  int len;

  len = strlen (base);
  temp_filename = XNEWVEC (char, len + TEMP_FILE_LEN + 1);
  strcpy (temp_filename, base);
  strcpy (temp_filename + len, TEMP_FILE);

  if (mktemp (temp_filename) == 0)
    abort ();
  return temp_filename;
}
