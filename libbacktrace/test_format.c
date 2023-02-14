/* test_format.c -- Test for libbacktrace library */

/* This program tests the externally visible interfaces of the
   libbacktrace library.  */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "filenames.h"

#include "backtrace.h"
#include "backtrace-supported.h"

#include "testlib.h"

int
main (int argc ATTRIBUTE_UNUSED, char **argv)
{
  state = backtrace_create_state (argv[0], BACKTRACE_SUPPORTS_THREADS,
				  error_callback_create, NULL);

  exit (failures ? EXIT_FAILURE : EXIT_SUCCESS);
}
