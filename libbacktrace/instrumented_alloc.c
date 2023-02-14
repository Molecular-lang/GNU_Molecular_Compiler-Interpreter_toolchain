/* instrumented_alloc.c -- Memory allocation instrumented to fail when
   requested, for testing purposes.
 */

/* Include all the header files of alloc here, to make sure they're not
   processed when including alloc.c below, such that the redefinitions of malloc
   and realloc are only effective in alloc.c itself.  This does not work for
   config.h, because it's not wrapped in "#ifndef CONFIG_H\n#define CONFIG_H"
   and "#endif" but that does not seem to be harmful.  */

#include "config.h"

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <inttypes.h>

#include "backtrace.h"
#include "internal.h"

extern void *instrumented_malloc (size_t size);
extern void *instrumented_realloc (void *ptr, size_t size);

#define malloc instrumented_malloc
#define realloc instrumented_realloc
#include "alloc.c"
#undef malloc
#undef realloc

static uint64_t nr_allocs = 0;
static uint64_t fail_at_alloc = 0;

extern int at_fail_alloc_p (void);
extern uint64_t get_nr_allocs (void);
extern void set_fail_at_alloc (uint64_t);

void *
instrumented_malloc (size_t size)
{
  void *res;

  if (at_fail_alloc_p ())
    return NULL;

  res = malloc (size);
  if (res != NULL)
    nr_allocs++;

  return res;
}

void *
instrumented_realloc (void *ptr, size_t size)
{
  void *res;

  if (size != 0)
    {
      if (at_fail_alloc_p ())
	return NULL;
    }

  res = realloc (ptr, size);
  if (res != NULL)
    nr_allocs++;

  return res;
}

int
at_fail_alloc_p (void)
{
  return fail_at_alloc == nr_allocs + 1;
}

uint64_t
get_nr_allocs (void)
{
  return nr_allocs;
}

void
set_fail_at_alloc (uint64_t nr)
{
  fail_at_alloc = nr;
}
