/* unittest.c -- Test for libbacktrace library */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "filenames.h"

#include "backtrace.h"
#include "backtrace-supported.h"

#include "testlib.h"

#include "internal.h"

static unsigned count;

static void
error_callback (void *vdata ATTRIBUTE_UNUSED, const char *msg ATTRIBUTE_UNUSED,
		int errnum ATTRIBUTE_UNUSED)
{
  ++count;
}

static int
test1 (void)
{
  int res;
  int failed;

  struct backtrace_vector vec;

  memset (&vec, 0, sizeof vec);

  backtrace_vector_grow (state, 100, error_callback, NULL, &vec);
  vec.alc += vec.size;
  vec.size = 0;

  count = 0;
  res = backtrace_vector_release (state, &vec, error_callback, NULL);
  failed = res != 1 || count != 0 || vec.base != NULL;

  printf ("%s: unittest backtrace_vector_release size == 0\n",
	  failed ? "FAIL": "PASS");

  if (failed)
    ++failures;

  return failures;
}

int
main (int argc ATTRIBUTE_UNUSED, char **argv)
{
  state = backtrace_create_state (argv[0], BACKTRACE_SUPPORTS_THREADS,
				  error_callback_create, NULL);

  test1 ();

  exit (failures ? EXIT_FAILURE : EXIT_SUCCESS);
}
