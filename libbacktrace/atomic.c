/* atomic.c -- Support for atomic functions if not present. */

#include "config.h"

#include <sys/types.h>

#include "backtrace.h"
#include "backtrace-supported.h"
#include "internal.h"

/* This file holds implementations of the atomic functions that are
   used if the host compiler has the sync functions but not the atomic
   functions, as is true of versions of GCC before 4.7.  */

#if !defined (HAVE_ATOMIC_FUNCTIONS) && defined (HAVE_SYNC_FUNCTIONS)

/* Do an atomic load of a pointer.  */

void *
backtrace_atomic_load_pointer (void *arg)
{
  void **pp;
  void *p;

  pp = (void **) arg;
  p = *pp;
  while (!__sync_bool_compare_and_swap (pp, p, p))
    p = *pp;
  return p;
}

/* Do an atomic load of an int.  */

int
backtrace_atomic_load_int (int *p)
{
  int i;

  i = *p;
  while (!__sync_bool_compare_and_swap (p, i, i))
    i = *p;
  return i;
}

/* Do an atomic store of a pointer.  */

void
backtrace_atomic_store_pointer (void *arg, void *p)
{
  void **pp;
  void *old;

  pp = (void **) arg;
  old = *pp;
  while (!__sync_bool_compare_and_swap (pp, old, p))
    old = *pp;
}

/* Do an atomic store of a size_t value.  */

void
backtrace_atomic_store_size_t (size_t *p, size_t v)
{
  size_t old;

  old = *p;
  while (!__sync_bool_compare_and_swap (p, old, v))
    old = *p;
}

/* Do an atomic store of a int value.  */

void
backtrace_atomic_store_int (int *p, int v)
{
  size_t old;

  old = *p;
  while (!__sync_bool_compare_and_swap (p, old, v))
    old = *p;
}

#endif
