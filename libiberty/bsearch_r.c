/*
 * Please review: $(src-dir)/SPL-README for Licencing info.
 */

/*

@deftypefn Supplemental void* bsearch_r (const void *@var{key}, @
  const void *@var{base}, size_t @var{nmemb}, size_t @var{size}, @
  int (*@var{compar})(const void *, const void *, void *), void *@var{arg})

Performs a search over an array of @var{nmemb} elements pointed to by
@var{base} for a member that matches the object pointed to by @var{key}.
The size of each member is specified by @var{size}.  The array contents
should be sorted in ascending order according to the @var{compar}
comparison function.  This routine should take three arguments: the first
two point to the @var{key} and to an array member, and the last is passed
down unchanged from @code{bsearch_r}'s last argument.  It should return an
integer less than, equal to, or greater than zero if the @var{key} object
is respectively less than, matching, or greater than the array member.

@end deftypefn

*/

#include "config.h"
#include "ansidecl.h"
#include <sys/types.h>		/* size_t */
#include <stdio.h>

/*
 * Perform a binary search.
 *
 * The code below is a bit sneaky.  After a comparison fails, we
 * divide the work in half by moving either left or right. If lim
 * is odd, moving left simply involves halving lim: e.g., when lim
 * is 5 we look at item 2, so we change lim to 2 so that we will
 * look at items 0 & 1.  If lim is even, the same applies.  If lim
 * is odd, moving right again involes halving lim, this time moving
 * the base up one item past p: e.g., when lim is 5 we change base
 * to item 3 and make lim 2 so that we will look at items 3 and 4.
 * If lim is even, however, we have to shrink it by one before
 * halving: e.g., when lim is 4, we still looked at item 2, so we
 * have to make lim 3, then halve, obtaining 1, so that we will only
 * look at item 3.
 */
void *
bsearch_r (const void *key, const void *base0,
	   size_t nmemb, size_t size,
	   int (*compar)(const void *, const void *, void *),
	   void *arg)
{
	const char *base = (const char *) base0;
	int lim, cmp;
	const void *p;

	for (lim = nmemb; lim != 0; lim >>= 1) {
		p = base + (lim >> 1) * size;
		cmp = (*compar)(key, p, arg);
		if (cmp == 0)
			return (void *)p;
		if (cmp > 0) {	/* key > p: move right */
			base = (const char *)p + size;
			lim--;
		} /* else move left */
	}
	return (NULL);
}
