/* posix.c -- POSIX file I/O routines for the backtrace library. */

#include "config.h"

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "backtrace.h"
#include "internal.h"

#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifndef O_CLOEXEC
#define O_CLOEXEC 0
#endif

#ifndef FD_CLOEXEC
#define FD_CLOEXEC 1
#endif

/* Open a file for reading.  */

int
backtrace_open (const char *filename, backtrace_error_callback error_callback,
		void *data, int *does_not_exist)
{
  int descriptor;

  if (does_not_exist != NULL)
    *does_not_exist = 0;

  descriptor = open (filename, (int) (O_RDONLY | O_BINARY | O_CLOEXEC));
  if (descriptor < 0)
    {
      /* If DOES_NOT_EXIST is not NULL, then don't call ERROR_CALLBACK
	 if the file does not exist.  We treat lacking permission to
	 open the file as the file not existing; this case arises when
	 running the libgo syscall package tests as root.  */
      if (does_not_exist != NULL && (errno == ENOENT || errno == EACCES))
	*does_not_exist = 1;
      else
	error_callback (data, filename, errno);
      return -1;
    }

#ifdef HAVE_FCNTL
  /* Set FD_CLOEXEC just in case the kernel does not support
     O_CLOEXEC. It doesn't matter if this fails for some reason.
     FIXME: At some point it should be safe to only do this if
     O_CLOEXEC == 0.  */
  fcntl (descriptor, F_SETFD, FD_CLOEXEC);
#endif

  return descriptor;
}

/* Close DESCRIPTOR.  */

int
backtrace_close (int descriptor, backtrace_error_callback error_callback,
		 void *data)
{
  if (close (descriptor) < 0)
    {
      error_callback (data, "close", errno);
      return 0;
    }
  return 1;
}
