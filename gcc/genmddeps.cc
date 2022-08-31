/* genmddeps.cc - creates a makefile dependency fragment for the md file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bconfig.h"
#include "system.h"
#include "coretypes.h"
#include "errors.h"
#include "statistics.h"
#include "vec.h"
#include "read-md.h"


struct filedep
{
  struct filedep *next;
  const char *pathname;
};

static struct filedep *deps, **last = &deps;

static void
add_filedep (const char *pathname)
{
  struct filedep *n = XNEW (struct filedep);
  n->pathname = pathname;
  *last = n;
  last = &n->next;
}

int
main (int argc, const char **argv)
{
  struct filedep *d;

  progname = "genmddeps";
  include_callback = add_filedep;

  noop_reader reader;
  if (!reader.read_md_files (argc, argv, NULL))
    return FATAL_EXIT_CODE;

  *last = NULL;

  /* Output a variable containing all of the include files.  */
  fputs ("MD_INCLUDES =", stdout);
  for (d = deps; d ; d = d->next)
    printf (" \\\n\t%s", d->pathname);
  putchar ('\n');

  /* Output make targets for these includes with empty actions.  This
     will guard against make errors when includes are removed.  */
  for (d = deps; d ; d = d->next)
    printf ("\n%s:\n", d->pathname);

  fflush (stdout);
  return (ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE);
}
