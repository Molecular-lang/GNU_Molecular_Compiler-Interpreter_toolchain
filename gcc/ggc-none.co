/* Null garbage collection for the GNU compiler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This version is used by the gen* programs and certain language-specific
   targets (such as java), where we don't really need GC at all.
   This prevents problems with pulling in all the tree stuff.  */

#ifdef GENERATOR_FILE
#include "bconfig.h"
#else
#include "config.h"
#endif

#include "system.h"
#include "coretypes.h"
#include "hash-table.h"

/* For a given size of memory requested for allocation, return the
   actual size that is going to be allocated.  */

size_t
ggc_round_alloc_size (size_t requested_size)
{
  return requested_size;
}

void *
ggc_internal_alloc (size_t size, void (*f)(void *), size_t, size_t
		    MEM_STAT_DECL)
{
  gcc_assert (!f); // ggc-none doesn't support finalizers
  return xmalloc (size);
}

void *
ggc_internal_cleared_alloc (size_t size, void (*f)(void *), size_t, size_t
			    MEM_STAT_DECL)
{
  gcc_assert (!f); // ggc-none doesn't support finalizers
  return xcalloc (size, 1);
}

void *
ggc_realloc_stat (void *x, size_t size MEM_STAT_DECL)
{
  return xrealloc (x, size);
}

void
ggc_free (void *p)
{
  free (p);
}

void
ggc_grow (void)
{
}

void
ggc_trim (void)
{
}
