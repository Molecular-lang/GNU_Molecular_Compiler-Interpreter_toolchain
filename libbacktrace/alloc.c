/* alloc.c -- Memory allocation without mmap.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>

#include "backtrace.h"
#include "internal.h"

/* Allocation routines to use on systems that do not support anonymous
   mmap.  This implementation just uses malloc, which means that the
   backtrace functions may not be safely invoked from a signal
   handler.  */

/* Allocate memory like malloc.  If ERROR_CALLBACK is NULL, don't
   report an error.  */

void *
backtrace_alloc (struct backtrace_state *state ATTRIBUTE_UNUSED,
		 size_t size, backtrace_error_callback error_callback,
		 void *data)
{
  void *ret;

  ret = malloc (size);
  if (ret == NULL)
    {
      if (error_callback)
	error_callback (data, "malloc", errno);
    }
  return ret;
}

/* Free memory.  */

void
backtrace_free (struct backtrace_state *state ATTRIBUTE_UNUSED,
		void *p, size_t size ATTRIBUTE_UNUSED,
		backtrace_error_callback error_callback ATTRIBUTE_UNUSED,
		void *data ATTRIBUTE_UNUSED)
{
  free (p);
}

/* Grow VEC by SIZE bytes.  */

void *
backtrace_vector_grow (struct backtrace_state *state ATTRIBUTE_UNUSED,
		       size_t size, backtrace_error_callback error_callback,
		       void *data, struct backtrace_vector *vec)
{
  void *ret;

  if (size > vec->alc)
    {
      size_t alc;
      void *base;

      if (vec->size == 0)
	alc = 32 * size;
      else if (vec->size >= 4096)
	alc = vec->size + 4096;
      else
	alc = 2 * vec->size;

      if (alc < vec->size + size)
	alc = vec->size + size;

      base = realloc (vec->base, alc);
      if (base == NULL)
	{
	  error_callback (data, "realloc", errno);
	  return NULL;
	}

      vec->base = base;
      vec->alc = alc - vec->size;
    }

  ret = (char *) vec->base + vec->size;
  vec->size += size;
  vec->alc -= size;
  return ret;
}

/* Finish the current allocation on VEC.  */

void *
backtrace_vector_finish (struct backtrace_state *state,
			 struct backtrace_vector *vec,
			 backtrace_error_callback error_callback,
			 void *data)
{
  void *ret;

  /* With this allocator we call realloc in backtrace_vector_grow,
     which means we can't easily reuse the memory here.  So just
     release it.  */
  if (!backtrace_vector_release (state, vec, error_callback, data))
    return NULL;
  ret = vec->base;
  vec->base = NULL;
  vec->size = 0;
  vec->alc = 0;
  return ret;
}

/* Release any extra space allocated for VEC.  */

int
backtrace_vector_release (struct backtrace_state *state ATTRIBUTE_UNUSED,
			  struct backtrace_vector *vec,
			  backtrace_error_callback error_callback,
			  void *data)
{
  vec->alc = 0;

  if (vec->size == 0)
    {
      /* As of C17, realloc with size 0 is marked as an obsolescent feature, use
	 free instead.  */
      free (vec->base);
      vec->base = NULL;
      return 1;
    }

  vec->base = realloc (vec->base, vec->size);
  if (vec->base == NULL)
    {
      error_callback (data, "realloc", errno);
      return 0;
    }

  return 1;
}
