/* File descriptor related functions. */

#include "config.h"
#include "ansidecl.h"
#include "libiberty.h"

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#if defined (_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h> /* for GetFullPathName */
#endif
/* Return true when FD file descriptor exists.  */

int
is_valid_fd (int fd)
{
#if defined(_WIN32)
  HANDLE h = (HANDLE) _get_osfhandle (fd);
  return h != (HANDLE) -1;
#elif defined(F_GETFD)
  return fcntl (fd, F_GETFD) >= 0;
#else
  return dup2 (fd, fd) < 0;
#endif
}
