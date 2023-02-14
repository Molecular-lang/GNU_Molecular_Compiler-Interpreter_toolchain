/* Implementation of threads compatibility routines for libgcc2.  */

/* This module is separate from the rest of the implementation because it
   references symbols in system libraries that are only available on Vista
   and Server 2008 or later versions.  */

/* Get the out-of-line version of the inline routines.  */

#if _WIN32_WINNT < 0x0600
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#define __GTHREAD_WIN32_COND_INLINE

#define __gthread_cond_init_function __gthr_win32_cond_init_function
#define __gthread_cond_broadcast __gthr_win32_cond_broadcast
#define __gthread_cond_signal __gthr_win32_cond_signal
#define __gthread_cond_wait __gthr_win32_cond_wait
#define __gthread_cond_timedwait __gthr_win32_cond_timedwait

#include "gthr-win32.h"

/* The number of 100-nanoseconds between 1/1/1601 and 1/1/1970. */
#define FILETIME_1970 116444736000000000ULL

/* The number of 100-nanoseconds per second.  */
#define NSEC100_PER_SEC (1000000000ULL / 100)

/* The number of 100-nanoseconds per millisecond.  */
#define NSEC100_PER_MSEC (NSEC100_PER_SEC / 1000)

/* The ceiling division of X by Y.  */
#define CEIL_DIV(X, Y) (((X) + (Y) - 1) / (Y))

/* Convert absolute thread time to relative time in millisecond.  */

DWORD
__gthr_win32_abs_to_rel_time (const __gthread_time_t *abs_time)
{
  union {
    ULONGLONG nsec100;
    FILETIME ft;
  } now;
  ULONGLONG abs_time_nsec100;

  /* The Windows epoch is 1/1/1601 while the Unix epoch is 1/1/1970.  */
  GetSystemTimeAsFileTime (&now.ft);
  now.nsec100 -= FILETIME_1970;

  abs_time_nsec100
    = (ULONGLONG) abs_time->tv_sec * NSEC100_PER_SEC
	+ CEIL_DIV (abs_time->tv_nsec, 100);

  if (abs_time_nsec100 < now.nsec100)
    return 0;

  return (DWORD) CEIL_DIV (abs_time_nsec100 - now.nsec100, NSEC100_PER_SEC);
}

/* Check the sizes of the local version of the Win32 types.  */

#define CHECK_SIZE_OF(TYPE) \
  typedef int assertion[sizeof(__gthr_win32_##TYPE) == sizeof(TYPE) ? 1 : -1];

CHECK_SIZE_OF (CONDITION_VARIABLE)
