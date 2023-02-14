/* backtrace.c -- Entry point for stack backtrace library. */

#include "config.h"

#include <sys/types.h>

#include "backtrace.h"

#include "internal.h"

/* This source file is compiled if the unwind library is not
   available.  */

int
backtrace_full (struct backtrace_state *state ATTRIBUTE_UNUSED,
		int skip ATTRIBUTE_UNUSED,
		backtrace_full_callback callback ATTRIBUTE_UNUSED,
		backtrace_error_callback error_callback, void *data)
{
  error_callback (data,
		  "no stack trace because unwind library not available",
		  0);
  return 0;
}

int
backtrace_simple (struct backtrace_state *state ATTRIBUTE_UNUSED,
		  int skip ATTRIBUTE_UNUSED,
		  backtrace_simple_callback callback ATTRIBUTE_UNUSED,
		  backtrace_error_callback error_callback, void *data)
{
  error_callback (data,
		  "no stack trace because unwind library not available",
		  0);
  return 0;
}
