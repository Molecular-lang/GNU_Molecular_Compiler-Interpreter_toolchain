/* mmapio.c -- File views using mmap.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

#include "backtrace.h"
#include "internal.h"

#ifndef HAVE_DECL_GETPAGESIZE
extern int getpagesize (void);
#endif

#ifndef MAP_FAILED
#define MAP_FAILED ((void *)-1)
#endif

/* This file implements file views and memory allocation when mmap is
   available.  */

/* Create a view of SIZE bytes from DESCRIPTOR at OFFSET.  */

int
backtrace_get_view (struct backtrace_state *state ATTRIBUTE_UNUSED,
		    int descriptor, off_t offset, uint64_t size,
		    backtrace_error_callback error_callback,
		    void *data, struct backtrace_view *view)
{
  size_t pagesize;
  unsigned int inpage;
  off_t pageoff;
  void *map;

  if ((uint64_t) (size_t) size != size)
    {
      error_callback (data, "file size too large", 0);
      return 0;
    }

  pagesize = getpagesize ();
  inpage = offset % pagesize;
  pageoff = offset - inpage;

  size += inpage;
  size = (size + (pagesize - 1)) & ~ (pagesize - 1);

  map = mmap (NULL, size, PROT_READ, MAP_PRIVATE, descriptor, pageoff);
  if (map == MAP_FAILED)
    {
      error_callback (data, "mmap", errno);
      return 0;
    }

  view->data = (char *) map + inpage;
  view->base = map;
  view->len = size;

  return 1;
}

/* Release a view read by backtrace_get_view.  */

void
backtrace_release_view (struct backtrace_state *state ATTRIBUTE_UNUSED,
			struct backtrace_view *view,
			backtrace_error_callback error_callback,
			void *data)
{
  union {
    const void *cv;
    void *v;
  } const_cast;

  const_cast.cv = view->base;
  if (munmap (const_cast.v, view->len) < 0)
    error_callback (data, "munmap", errno);
}
