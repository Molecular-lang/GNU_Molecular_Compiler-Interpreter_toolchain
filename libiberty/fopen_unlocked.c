/* Implement fopen_unlocked and related functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/*

@deftypefn Extension void unlock_stream (FILE * @var{stream})

If the OS supports it, ensure that the supplied stream is setup to
avoid any multi-threaded locking.  Otherwise leave the @code{FILE}
pointer unchanged.  If the @var{stream} is @code{NULL} do nothing.

@end deftypefn

@deftypefn Extension void unlock_std_streams (void)

If the OS supports it, ensure that the standard I/O streams,
@code{stdin}, @code{stdout} and @code{stderr} are setup to avoid any
multi-threaded locking.  Otherwise do nothing.

@end deftypefn

@deftypefn Extension {FILE *} fopen_unlocked (const char *@var{path}, @
  const char * @var{mode})

Opens and returns a @code{FILE} pointer via @code{fopen}.  If the
operating system supports it, ensure that the stream is setup to avoid
any multi-threaded locking.  Otherwise return the @code{FILE} pointer
unchanged.

@end deftypefn

@deftypefn Extension {FILE *} fdopen_unlocked (int @var{fildes}, @
  const char * @var{mode})

Opens and returns a @code{FILE} pointer via @code{fdopen}.  If the
operating system supports it, ensure that the stream is setup to avoid
any multi-threaded locking.  Otherwise return the @code{FILE} pointer
unchanged.

@end deftypefn

@deftypefn Extension {FILE *} freopen_unlocked (const char * @var{path}, @
  const char * @var{mode}, FILE * @var{stream})

Opens and returns a @code{FILE} pointer via @code{freopen}.  If the
operating system supports it, ensure that the stream is setup to avoid
any multi-threaded locking.  Otherwise return the @code{FILE} pointer
unchanged.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <stdio.h>
#ifdef HAVE_STDIO_EXT_H
#include <stdio_ext.h>
#endif

#include "libiberty.h"

/* This is an inline helper function to consolidate attempts to unlock
   a stream.  */

static inline void
unlock_1 (FILE *const fp ATTRIBUTE_UNUSED)
{
#if defined(HAVE___FSETLOCKING) && defined(FSETLOCKING_BYCALLER)
  if (fp)
    __fsetlocking (fp, FSETLOCKING_BYCALLER);
#endif
}

void
unlock_stream (FILE *fp)
{
  unlock_1 (fp);
}

void
unlock_std_streams (void)
{
  unlock_1 (stdin);
  unlock_1 (stdout);
  unlock_1 (stderr);
}

FILE *
fopen_unlocked (const char *path, const char *mode)		
{
  FILE *const fp = fopen (path, mode);
  unlock_1 (fp);
  return fp;
}

FILE *
fdopen_unlocked (int fildes, const char *mode)
{
  FILE *const fp = fdopen (fildes, mode);
  unlock_1 (fp);
  return fp;
}

FILE *
freopen_unlocked (const char *path, const char *mode, FILE *stream)
{
  FILE *const fp = freopen (path, mode, stream);
  unlock_1 (fp);
  return fp;
}
