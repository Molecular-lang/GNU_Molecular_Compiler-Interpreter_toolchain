/* allocfail.c -- Test for libbacktrace library
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "filenames.h"

#include "backtrace.h"
#include "backtrace-supported.h"

#include "testlib.h"

extern uint64_t get_nr_allocs (void);
extern void set_fail_at_alloc (uint64_t);
extern int at_fail_alloc_p (void);

static int test1 (void) __attribute__ ((noinline, unused));
static int f2 (int) __attribute__ ((noinline));
static int f3 (int, int) __attribute__ ((noinline));

static unsigned callback_errors = 0;

static void
error_callback_full (void *vdata ATTRIBUTE_UNUSED, const char *msg ATTRIBUTE_UNUSED, int errnum ATTRIBUTE_UNUSED)
{
  if (at_fail_alloc_p ())
    {
      set_fail_at_alloc (0);
      return;
    }

  callback_errors++;
}

static int
callback_full (void *vdata ATTRIBUTE_UNUSED, uintptr_t pc ATTRIBUTE_UNUSED,
	      const char *filename ATTRIBUTE_UNUSED,
	      int lineno ATTRIBUTE_UNUSED,
	      const char *function ATTRIBUTE_UNUSED)
{

  return 0;
}

static int
test1 (void)
{
  return f2 (__LINE__) + 1;
}

static int
f2 (int f1line)
{
  return f3 (f1line, __LINE__) + 2;
}

static int
f3 (int f1line ATTRIBUTE_UNUSED, int f2line ATTRIBUTE_UNUSED)
{
  int i;

  i = backtrace_full (state, 0, callback_full, error_callback_full, NULL);

  if (i != 0)
    {
      fprintf (stderr, "test1: unexpected return value %d\n", i);
      ++failures;
    }

  if (callback_errors)
      ++failures;

  return failures;
}

/* Run all the tests.  */

int
main (int argc, char **argv)
{
  uint64_t fail_at = 0;

  if (argc == 2)
    {
      fail_at = atoi (argv[1]);
      set_fail_at_alloc (fail_at);
    }

  state = backtrace_create_state (argv[0], BACKTRACE_SUPPORTS_THREADS,
				  error_callback_full, NULL);
  if (state == NULL)
    exit (failures ? EXIT_FAILURE : EXIT_SUCCESS);

#if BACKTRACE_SUPPORTED
  test1 ();
#endif

  if (argc == 1)
    fprintf (stderr, "%llu\n", (long long unsigned) get_nr_allocs ());

  exit (failures ? EXIT_FAILURE : EXIT_SUCCESS);
}
