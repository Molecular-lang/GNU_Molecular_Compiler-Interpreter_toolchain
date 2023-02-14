#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED

#include <stdlib.h>
#if __STDC_HOSTED__
#include <errno.h>
#endif

static __inline__ void * 
_mm_malloc (size_t __size, size_t __align)
{
  void * __malloc_ptr;
  void * __aligned_ptr;

  /* Error if align is not a power of two.  */
  if (__align & (__align - 1))
    {
#if __STDC_HOSTED__
      errno = EINVAL;
#endif
      return ((void *) 0);
    }

  if (__size == 0)
    return ((void *) 0);

 /* Assume malloc'd pointer is aligned at least to sizeof (void*).
    If necessary, add another sizeof (void*) to store the value
    returned by malloc. Effectively this enforces a minimum alignment
    of sizeof double. */     
    if (__align < 2 * sizeof (void *))
      __align = 2 * sizeof (void *);

  __malloc_ptr = malloc (__size + __align);
  if (!__malloc_ptr)
    return ((void *) 0);

  /* Align  We have at least sizeof (void *) space below malloc'd ptr. */
  __aligned_ptr = (void *) (((size_t) __malloc_ptr + __align)
			    & ~((size_t) (__align) - 1));

  /* Store the original pointer just before p.  */	
  ((void **) __aligned_ptr)[-1] = __malloc_ptr;

  return __aligned_ptr;
}

static __inline__ void
_mm_free (void *__aligned_ptr)
{
  if (__aligned_ptr)
    free (((void **) __aligned_ptr)[-1]);
}

#endif /* _MM_MALLOC_H_INCLUDED */
