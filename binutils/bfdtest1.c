/* A program to test BFD. */

#include "sysdep.h"
#include "bfd.h"

static void
die (const char *s)
{
  printf ("oops: %s\n", s);
  exit (1);
}

int
main (int argc, char **argv)
{
  bfd *archive;
  bfd *last, *next;

  if (argc != 2)
    die ("usage: bfdtest1 <archive>");

  archive = bfd_openr (argv[1], NULL);
  if (archive == NULL)
    die ("no such archive");

  if (!bfd_check_format (archive, bfd_archive))
    {
      bfd_close (archive);
      die ("bfd_check_format");
    }

  for (last = bfd_openr_next_archived_file (archive, NULL);
       last;
       last = next)
    {
      next = bfd_openr_next_archived_file (archive, last);
      bfd_close (last);
    }

  for (last = bfd_openr_next_archived_file (archive, NULL);
       last;
       last = next)
    {
      next = bfd_openr_next_archived_file (archive, last);
      bfd_close (last);
    }

  if (!bfd_close (archive))
    die ("bfd_close");

  return 0;
}
