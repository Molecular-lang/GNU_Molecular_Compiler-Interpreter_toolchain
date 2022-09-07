/* testlib.c -- test functions for libbacktrace library
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filenames.h"

#include "backtrace.h"

#include "testlib.h"

/* The backtrace state.  */

void *state;

/* The number of failures.  */

int failures;

/* Return the base name in a path.  */

const char *
base (const char *p)
{
  const char *last;
  const char *s;

  last = NULL;
  for (s = p; *s != '\0'; ++s)
    {
      if (IS_DIR_SEPARATOR (*s))
	last = s + 1;
    }
  return last != NULL ? last : p;
}

/* Check an entry in a struct info array.  */

void
check (const char *name, int index, const struct info *all, int want_lineno,
       const char *want_function, const char *want_file, int *failed)
{
  if (*failed)
    return;
  if (all[index].filename == NULL || all[index].function == NULL)
    {
      fprintf (stderr, "%s: [%d]: missing file name or function name\n",
	       name, index);
      *failed = 1;
      return;
    }
  if (strcmp (base (all[index].filename), want_file) != 0)
    {
      fprintf (stderr, "%s: [%d]: got %s expected %s\n", name, index,
	       all[index].filename, want_file);
      *failed = 1;
    }
  if (all[index].lineno != want_lineno)
    {
      fprintf (stderr, "%s: [%d]: got %d expected %d\n", name, index,
	       all[index].lineno, want_lineno);
      *failed = 1;
    }
  if (strcmp (all[index].function, want_function) != 0)
    {
      fprintf (stderr, "%s: [%d]: got %s expected %s\n", name, index,
	       all[index].function, want_function);
      *failed = 1;
    }
}

/* The backtrace callback function.  */

int
callback_one (void *vdata, uintptr_t pc ATTRIBUTE_UNUSED,
	      const char *filename, int lineno, const char *function)
{
  struct bdata *data = (struct bdata *) vdata;
  struct info *p;

  if (data->index >= data->max)
    {
      fprintf (stderr, "callback_one: callback called too many times\n");
      data->failed = 1;
      return 1;
    }

  p = &data->all[data->index];
  if (filename == NULL)
    p->filename = NULL;
  else
    {
      p->filename = strdup (filename);
      assert (p->filename != NULL);
    }
  p->lineno = lineno;
  if (function == NULL)
    p->function = NULL;
  else
    {
      p->function = strdup (function);
      assert (p->function != NULL);
    }
  ++data->index;

  return 0;
}

/* An error callback passed to backtrace.  */

void
error_callback_one (void *vdata, const char *msg, int errnum)
{
  struct bdata *data = (struct bdata *) vdata;

  fprintf (stderr, "%s", msg);
  if (errnum > 0)
    fprintf (stderr, ": %s", strerror (errnum));
  fprintf (stderr, "\n");
  data->failed = 1;
}

/* The backtrace_simple callback function.  */

int
callback_two (void *vdata, uintptr_t pc)
{
  struct sdata *data = (struct sdata *) vdata;

  if (data->index >= data->max)
    {
      fprintf (stderr, "callback_two: callback called too many times\n");
      data->failed = 1;
      return 1;
    }

  data->addrs[data->index] = pc;
  ++data->index;

  return 0;
}

/* An error callback passed to backtrace_simple.  */

void
error_callback_two (void *vdata, const char *msg, int errnum)
{
  struct sdata *data = (struct sdata *) vdata;

  fprintf (stderr, "%s", msg);
  if (errnum > 0)
    fprintf (stderr, ": %s", strerror (errnum));
  fprintf (stderr, "\n");
  data->failed = 1;
}

/* The backtrace_syminfo callback function.  */

void
callback_three (void *vdata, uintptr_t pc ATTRIBUTE_UNUSED,
		const char *symname, uintptr_t symval,
		uintptr_t symsize)
{
  struct symdata *data = (struct symdata *) vdata;

  if (symname == NULL)
    data->name = NULL;
  else
    {
      data->name = strdup (symname);
      assert (data->name != NULL);
    }
  data->val = symval;
  data->size = symsize;
}

/* The backtrace_syminfo error callback function.  */

void
error_callback_three (void *vdata, const char *msg, int errnum)
{
  struct symdata *data = (struct symdata *) vdata;

  fprintf (stderr, "%s", msg);
  if (errnum > 0)
    fprintf (stderr, ": %s", strerror (errnum));
  fprintf (stderr, "\n");
  data->failed = 1;
}

/* The backtrace_create_state error callback function.  */

void
error_callback_create (void *data ATTRIBUTE_UNUSED, const char *msg,
                       int errnum)
{
  fprintf (stderr, "%s", msg);
  if (errnum > 0)
    fprintf (stderr, ": %s", strerror (errnum));
  fprintf (stderr, "\n");
  exit (EXIT_FAILURE);
}
