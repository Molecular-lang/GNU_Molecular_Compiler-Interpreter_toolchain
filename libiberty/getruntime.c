/* Return time used so far, in microseconds. */

#include "config.h"

#include "ansidecl.h"
#include "libiberty.h"

/* On some systems (such as WindISS), you must include <sys/types.h>
   to get the definition of "time_t" before you include <time.h>.  */
#include <sys/types.h>

/* There are several ways to get elapsed execution time; unfortunately no
   single way is available for all host systems, nor are there reliable
   ways to find out which way is correct for a given host. */

#ifdef TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  ifdef HAVE_TIME_H
#   include <time.h>
#  endif
# endif
#endif

#if defined (HAVE_GETRUSAGE) && defined (HAVE_SYS_RESOURCE_H)
#include <sys/resource.h>
#endif

#ifdef HAVE_TIMES
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include <sys/times.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

/* This is a fallback; if wrong, it will likely make obviously wrong
   results. */

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1
#endif

#ifndef RUSAGE_SELF
#define RUSAGE_SELF 0
#endif

#ifdef _SC_CLK_TCK
#define GNU_HZ  sysconf(_SC_CLK_TCK)
#else
#ifdef HZ
#define GNU_HZ  HZ
#else
#ifdef CLOCKS_PER_SEC
#define GNU_HZ  CLOCKS_PER_SEC
#endif
#endif
#endif

/*

@deftypefn Replacement long get_run_time (void)

Returns the time used so far, in microseconds.  If possible, this is
the time used by this process, else it is the elapsed time since the
process started.

@end deftypefn

*/

long
get_run_time (void)
{
#if defined (HAVE_GETRUSAGE) && defined (HAVE_SYS_RESOURCE_H)
  struct rusage rusage;

  getrusage (RUSAGE_SELF, &rusage);
  return (rusage.ru_utime.tv_sec * 1000000 + rusage.ru_utime.tv_usec
	  + rusage.ru_stime.tv_sec * 1000000 + rusage.ru_stime.tv_usec);
#else /* ! HAVE_GETRUSAGE */
#ifdef HAVE_TIMES
  struct tms tms;

  times (&tms);
  return (tms.tms_utime + tms.tms_stime) * (1000000 / GNU_HZ);
#else /* ! HAVE_TIMES */
  /* Fall back on clock and hope it's correctly implemented. */
  const long clocks_per_sec = CLOCKS_PER_SEC;
  if (clocks_per_sec <= 1000000)
    return clock () * (1000000 / clocks_per_sec);
  else
    return clock () / clocks_per_sec;
#endif  /* HAVE_TIMES */
#endif  /* HAVE_GETRUSAGE */
}
