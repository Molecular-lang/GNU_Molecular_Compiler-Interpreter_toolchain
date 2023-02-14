/* edtest.c -- Test for libbacktrace storage allocation stress handling */

#include "config.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "backtrace.h"
#include "backtrace-supported.h"
#include "internal.h"

#include "testlib.h"

static int test1 (void) __attribute__ ((noinline, noclone, unused));
extern int f2 (int);
extern int f3 (int, int);

static int
test1 (void)
{
  /* Returning a value here and elsewhere avoids a tailcall which
     would mess up the backtrace.  */
  return f2 (__LINE__) + 1;
}

int
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

  check ("test1", 0, all, f3line, "f3", "edtest.c", &data.failed);
  check ("test1", 1, all, f2line, "f2", "edtest2_build.c", &data.failed);
  check ("test1", 2, all, f1line, "test1", "edtest.c", &data.failed);

  printf ("%s: backtrace_full alloc stress\n", data.failed ? "FAIL" : "PASS");

  if (data.failed)
    ++failures;

  return failures;
}

int
main (int argc ATTRIBUTE_UNUSED, char **argv ATTRIBUTE_UNUSED)
{
  state = backtrace_create_state (argv[0], BACKTRACE_SUPPORTS_THREADS,
                                  error_callback_create, NULL);

  // Grab the storage allocation lock prior to doing anything interesting.
  // The intent here is to insure that the backtrace_alloc code is forced
  // to always call mmap() for new memory as opposed to reusing previously
  // allocated memory from the free list. Doing things this way helps
  // simulate what you might see in a multithreaded program in which there
  // are racing calls to the allocator.
  struct backtrace_state *state_internal =
      (struct backtrace_state *) state;
  state_internal->lock_alloc = 1;

  // Kick off the test
  test1();

  exit (failures > 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}
