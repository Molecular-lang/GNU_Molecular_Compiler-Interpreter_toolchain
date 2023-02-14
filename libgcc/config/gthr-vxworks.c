/* Threads compatibility routines for libgcc2 for VxWorks.

   This file implements the init-once service exposed by gthr-vxworks.h.  */

#include "tconfig.h"
#include "tsystem.h"
#include "gthr.h"

#if defined(__GTHREADS)

#include <vxWorks.h>
#include <taskLib.h>

#ifndef __RTP__
# include <vxLib.h>
# include <taskHookLib.h>
#else /* __RTP__ */
# include <errno.h>
#endif /* __RTP__ */

/* ----------------------------- Init-once ------------------------------- */

static void
__release (__gthread_once_t ** __guard)
{
  (*__guard)->busy = 0;
}

int
__gthread_once (__gthread_once_t * __guard, void (*__func) (void))
{
  if (__guard->done)
    return 0;

  /* Busy-wait until we have exclusive access to the state.  Check if
     another thread managed to perform the init call in the interim.  */
  
  while (!__TAS(&__guard->busy))
    {
      if (__guard->done)
	return 0;
      taskDelay (1);
    }

  if (!__guard->done)
    {
#ifndef __USING_SJLJ_EXCEPTIONS__
      /* Setup a cleanup to release the guard when __func() throws an
	 exception.  We cannot use this with SJLJ exceptions as
	 Unwind_Register calls __gthread_once, leading to an infinite
	 recursion.  */
      __attribute__ ((cleanup (__release)))
	__gthread_once_t *__temp = __guard;
#endif

      __func ();
      __guard->done = 1;
    }

  __release(&__guard);
  return 0;
}

#endif /* __GTHREADS */
