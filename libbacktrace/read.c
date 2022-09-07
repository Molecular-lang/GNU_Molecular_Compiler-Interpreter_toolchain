/* read.c -- File views without mmap.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "backtrace.h"
#include "internal.h"

/* This file implements file views when mmap is not available.  */

/* Create a view of SIZE bytes from DESCRIPTOR at OFFSET.  */

int
backtrace_get_view (struct backtrace_state *state, int descriptor,
		    off_t offset, uint64_t size,
		    backtrace_error_callback error_callback,
		    void *data, struct backtrace_view *view)
{
  uint64_t got;
  ssize_t r;

  if ((uint64_t) (size_t) size != size)
    {
      error_callback (data, "file size too large", 0);
      return 0;
    }

  if (lseek (descriptor, offset, SEEK_SET) < 0)
    {
      error_callback (data, "lseek", errno);
      return 0;
    }

  view->base = backtrace_alloc (state, size, error_callback, data);
  if (view->base == NULL)
    return 0;
  view->data = view->base;
  view->len = size;

  got = 0;
  while (got < size)
    {
      r = read (descriptor, view->base, size - got);
      if (r < 0)
	{
	  error_callback (data, "read", errno);
	  free (view->base);
	  return 0;
	}
      if (r == 0)
	break;
      got += (uint64_t) r;
    }

  if (got < size)
    {
      error_callback (data, "file too short", 0);
      free (view->base);
      return 0;
    }

  return 1;
}

/* Release a view read by backtrace_get_view.  */

void
backtrace_release_view (struct backtrace_state *state,
			struct backtrace_view *view,
			backtrace_error_callback error_callback,
			void *data)
{
  backtrace_free (state, view->base, view->len, error_callback, data);
  view->data = NULL;
  view->base = NULL;
}
