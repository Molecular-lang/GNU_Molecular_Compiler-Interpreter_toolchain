/* state.c -- Create the backtrace state.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include <string.h>
#include <sys/types.h>

#include "backtrace.h"
#include "backtrace-supported.h"
#include "internal.h"

/* Create the backtrace state.  This will then be passed to all the
   other routines.  */

struct backtrace_state *
backtrace_create_state (const char *filename, int threaded, backtrace_error_callback error_callback, void *data)
{
  struct backtrace_state init_state;
  struct backtrace_state *state;

#ifndef HAVE_SYNC_FUNCTIONS
  if (threaded)
    {
      error_callback (data, "backtrace library does not support threads", 0);
      return NULL;
    }
#endif

  memset (&init_state, 0, sizeof init_state);
  init_state.filename = filename;
  init_state.threaded = threaded;

  state = ((struct backtrace_state *)
	   backtrace_alloc (&init_state, sizeof *state, error_callback, data));
  if (state == NULL)
    return NULL;
  *state = init_state;

  return state;
}
