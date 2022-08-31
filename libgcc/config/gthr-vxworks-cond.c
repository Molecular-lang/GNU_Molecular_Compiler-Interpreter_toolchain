/* Please review: $(src-dir)/SPL-README for Licencing info. */

/* Threads compatibility routines for libgcc2 for VxWorks.

   This file implements the GTHREAD_HAS_COND part of the interface
   exposed by gthr-vxworks.h.  */

#include "gthr.h"

#if __GTHREAD_HAS_COND

#include <taskLib.h>

/* --------------------------- Condition Variables ------------------------ */

void
__gthread_cond_init (__gthread_cond_t *cond)
{
  if (!cond)
    return;
  *cond = semBCreate (SEM_Q_FIFO, SEM_EMPTY);
}

int
__gthread_cond_destroy (__gthread_cond_t *cond)
{
  if (!cond)
    return ERROR;
  return __CHECK_RESULT (semDelete (*cond));
}

int
__gthread_cond_broadcast (__gthread_cond_t *cond)
{
  if (!cond)
    return ERROR;

  return __CHECK_RESULT (semFlush (*cond));
}

int
__gthread_cond_wait (__gthread_cond_t *cond,
		     __gthread_mutex_t *mutex)
{
  if (!cond)
    return ERROR;

  if (!mutex)
    return ERROR;

  int ret = __CHECK_RESULT (semExchange (*mutex, *cond, WAIT_FOREVER));

  __RETURN_ERRNO_IF_NOT_OK (semTake (*mutex, WAIT_FOREVER));

  return ret;
}

int
__gthread_cond_wait_recursive (__gthread_cond_t *cond,
			       __gthread_recursive_mutex_t *mutex)
{
  return __gthread_cond_wait (cond, mutex);
}

#endif
