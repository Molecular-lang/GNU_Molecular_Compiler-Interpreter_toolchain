/* unlink-if-ordinary.c - remove link to a file unless it is special */

/*

@deftypefn Supplemental int unlink_if_ordinary (const char*)

Unlinks the named file, unless it is special (e.g. a device file).
Returns 0 when the file was unlinked, a negative value (and errno set) when
there was an error deleting the file, and a positive value if no attempt
was made to unlink the file because it is special.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <sys/types.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#include "libiberty.h"

#ifndef S_ISLNK
#ifdef S_IFLNK
#define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#else
#define S_ISLNK(m) 0
#define lstat stat
#endif
#endif

int
unlink_if_ordinary (const char *name)
{
  struct stat st;

  if (lstat (name, &st) == 0
      && (S_ISREG (st.st_mode) || S_ISLNK (st.st_mode)))
    return unlink (name);

  return 1;
}
