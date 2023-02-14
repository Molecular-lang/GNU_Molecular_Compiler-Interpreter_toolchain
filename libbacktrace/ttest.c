/* ttest.c -- Test for libbacktrace library */

/* Test using the libbacktrace library from multiple threads.  */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#include "filenames.h"

#include "backtrace.h"
#include "backtrace-supported.h"

#include "testlib.h"

static int f2 (int) __attribute__ ((noinline));
static int f3 (int, int) __attribute__ ((noinline));

/* Test that a simple backtrace works.  This is called via
   pthread_create.  It returns the number of failures, as void *.  */

static void *
test1_thread (void *arg ATTRIBUTE_UNUSED)
{
  /* Returning a value here and elsewhere avoids a tailcall which
     would mess up the backtrace.  */
  return (void *) (uintptr_t) (f2 (__LINE__) - 2);
}

static int
f2 (int f1line)
{
  return f3 (f1line, __LINE__) + 2;
}

static int
f3 (int f1line, int f2line)
{
  struct info all[20];
  struct bdata data;
  int f3line;
  int i;

  data.all = &all[0];
  data.index = 0;
  data.max = 20;
  data.failed = 0;

  f3line = __LINE__ + 1;
  i = backtrace_full (state, 0, callback_one, error_callback_one, &data);

  if (i != 0)
    {
      fprintf (stderr, "test1: unexpected return value %d\n", i);
      data.failed = 1;
    }

  if (data.index < 3)
    {
      fprintf (stderr,
	       "test1: not enough frames; got %zu, expected at least 3\n",
	       data.index);
      data.failed = 1;
    }

  check ("test1", 0, all, f3line, "f3", "ttest.c", &data.failed);
  check ("test1", 1, all, f2line, "f2", "ttest.c", &data.failed);
  check ("test1", 2, all, f1line, "test1_thread", "ttest.c", &data.failed);

  return data.failed;
}

/* Run the test with 10 threads simultaneously.  */

#define THREAD_COUNT 10

static void test1 (void) __attribute__ ((unused));

static void
test1 (void)
{
  pthread_t atid[THREAD_COUNT];
  int i;
  int errnum;
  int this_fail;
  void *ret;

  for (i = 0; i < THREAD_COUNT; i++)
    {
      errnum = pthread_create (&atid[i], NULL, test1_thread, NULL);
      if (errnum != 0)
	{
	  fprintf (stderr, "pthread_create %d: %s\n", i, strerror (errnum));
	  exit (EXIT_FAILURE);
	}
    }

  this_fail = 0;
  for (i = 0; i < THREAD_COUNT; i++)
    {
      errnum = pthread_join (atid[i], &ret);
      if (errnum != 0)
	{
	  fprintf (stderr, "pthread_join %d: %s\n", i, strerror (errnum));
	  exit (EXIT_FAILURE);
	}
      this_fail += (int) (uintptr_t) ret;
    }

  printf ("%s: threaded backtrace_full noinline\n", this_fail > 0 ? "FAIL" : "PASS");

  failures += this_fail;
}

int
main (int argc ATTRIBUTE_UNUSED, char **argv)
{
  state = backtrace_create_state (argv[0], BACKTRACE_SUPPORTS_THREADS,
				  error_callback_create, NULL);

#if BACKTRACE_SUPPORTED
#if BACKTRACE_SUPPORTS_THREADS
  test1 ();
#endif
#endif

  exit (failures ? EXIT_FAILURE : EXIT_SUCCESS);
}
