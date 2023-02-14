/* print.c -- Print the current backtrace. */

#include "config.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "backtrace.h"
#include "internal.h"

/* Passed to callbacks.  */

struct print_data
{
  struct backtrace_state *state;
  FILE *f;
};

/* Print one level of a backtrace.  */

static int
print_callback (void *data, uintptr_t pc, const char *filename, int lineno,
		const char *function)
{
  struct print_data *pdata = (struct print_data *) data;

  fprintf (pdata->f, "0x%lx %s\n\t%s:%d\n",
	   (unsigned long) pc,
	   function == NULL ? "???" : function,
	   filename == NULL ? "???" : filename,
	   lineno);
  return 0;
}

/* Print errors to stderr.  */

static void
error_callback (void *data, const char *msg, int errnum)
{
  struct print_data *pdata = (struct print_data *) data;

  if (pdata->state->filename != NULL)
    fprintf (stderr, "%s: ", pdata->state->filename);
  fprintf (stderr, "libbacktrace: %s", msg);
  if (errnum > 0)
    fprintf (stderr, ": %s", strerror (errnum));
  fputc ('\n', stderr);
}

/* Print a backtrace.  */

void __attribute__((noinline))
backtrace_print (struct backtrace_state *state, int skip, FILE *f)
{
  struct print_data data;

  data.state = state;
  data.f = f;
  backtrace_full (state, skip + 1, print_callback, error_callback,
		  (void *) &data);
}
