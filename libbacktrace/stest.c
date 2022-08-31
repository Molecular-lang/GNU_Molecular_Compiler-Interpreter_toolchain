/* stest.c -- Test for libbacktrace internal sort function
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "backtrace.h"
#include "internal.h"

/* Test the local qsort implementation.  */

#define MAX 10

struct test
{
  size_t count;
  int input[MAX];
  int output[MAX];
};

static struct test tests[] =
  {
    {
      10,
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
    },
    {
      9,
      { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    },
    {
      10,
      { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
    },
    {
      9,
      { 9, 8, 7, 6, 5, 4, 3, 2, 1 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    },
    {
      10,
      { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
    },
    {
      5,
      { 4, 5, 3, 1, 2 },
      { 1, 2, 3, 4, 5 },
    },
    {
      5,
      { 1, 1, 1, 1, 1 },
      { 1, 1, 1, 1, 1 },
    },
    {
      5,
      { 1, 1, 2, 1, 1 },
      { 1, 1, 1, 1, 2 },
    },
    {
      5,
      { 2, 1, 1, 1, 1 },
      { 1, 1, 1, 1, 2 },
    },
  };

static int
compare (const void *a, const void *b)
{
  const int *ai = (const int *) a;
  const int *bi = (const int *) b;

  return *ai - *bi;
}

int
main (int argc ATTRIBUTE_UNUSED, char **argv ATTRIBUTE_UNUSED)
{
  int failures;
  size_t i;
  int a[MAX];

  failures = 0;
  for (i = 0; i < sizeof tests / sizeof tests[0]; i++)
    {
      memcpy (a, tests[i].input, tests[i].count * sizeof (int));
      backtrace_qsort (a, tests[i].count, sizeof (int), compare);
      if (memcmp (a, tests[i].output, tests[i].count * sizeof (int)) != 0)
	{
	  size_t j;

	  fprintf (stderr, "test %d failed:", (int) i);
	  for (j = 0; j < tests[i].count; j++)
	    fprintf (stderr, " %d", a[j]);
	  fprintf (stderr, "\n");
	  ++failures;
	}
    }

  exit (failures > 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}
