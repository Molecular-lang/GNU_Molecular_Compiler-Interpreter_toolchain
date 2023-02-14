/* sort.c -- Sort without allocating memory */

#include "config.h"

#include <stddef.h>
#include <sys/types.h>

#include "backtrace.h"
#include "internal.h"

/* The GNU glibc version of qsort allocates memory, which we must not
   do if we are invoked by a signal handler.  So provide our own
   sort.  */

static void
swap (char *a, char *b, size_t size)
{
  size_t i;

  for (i = 0; i < size; i++, a++, b++)
    {
      char t;

      t = *a;
      *a = *b;
      *b = t;
    }
}

void
backtrace_qsort (void *basearg, size_t count, size_t size,
		 int (*compar) (const void *, const void *))
{
  char *base = (char *) basearg;
  size_t i;
  size_t mid;

 tail_recurse:
  if (count < 2)
    return;

  /* The symbol table and DWARF tables, which is all we use this
     routine for, tend to be roughly sorted.  Pick the middle element
     in the array as our pivot point, so that we are more likely to
     cut the array in half for each recursion step.  */
  swap (base, base + (count / 2) * size, size);

  mid = 0;
  for (i = 1; i < count; i++)
    {
      if ((*compar) (base, base + i * size) > 0)
	{
	  ++mid;
	  if (i != mid)
	    swap (base + mid * size, base + i * size, size);
	}
    }

  if (mid > 0)
    swap (base, base + mid * size, size);

  /* Recurse with the smaller array, loop with the larger one.  That
     ensures that our maximum stack depth is log count.  */
  if (2 * mid < count)
    {
      backtrace_qsort (base, mid, size, compar);
      base += (mid + 1) * size;
      count -= mid + 1;
      goto tail_recurse;
    }
  else
    {
      backtrace_qsort (base + (mid + 1) * size, count - (mid + 1),
		       size, compar);
      count = mid;
      goto tail_recurse;
    }
}
