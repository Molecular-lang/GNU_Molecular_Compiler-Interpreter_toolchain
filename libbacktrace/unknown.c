/* unknown.c -- used when backtrace configury does not know file format.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include <sys/types.h>

#include "backtrace.h"
#include "internal.h"

/* A trivial routine that always fails to find fileline data.  */

static int
unknown_fileline (struct backtrace_state *state ATTRIBUTE_UNUSED,
		  uintptr_t pc, backtrace_full_callback callback,
		  backtrace_error_callback error_callback ATTRIBUTE_UNUSED,
		  void *data)

{
  return callback (data, pc, NULL, 0, NULL);
}

/* Initialize the backtrace data when we don't know how to read the
   debug info.  */

int
backtrace_initialize (struct backtrace_state *state ATTRIBUTE_UNUSED,
		      const char *filename ATTRIBUTE_UNUSED,
		      int descriptor ATTRIBUTE_UNUSED,
		      backtrace_error_callback error_callback ATTRIBUTE_UNUSED,
		      void *data ATTRIBUTE_UNUSED, fileline *fileline_fn)
{
  state->fileline_data = NULL;
  *fileline_fn = unknown_fileline;
  return 1;
}
