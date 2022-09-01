/* A program to test BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "sysdep.h"
#include "bfd.h"

static void
die (const char *s)
{
  printf ("oops: %s\n", s);
  exit (1);
}

static void *
iovec_open (struct bfd *nbfd ATTRIBUTE_UNUSED, void *open_closure)
{
  return open_closure;
}

static file_ptr iovec_read (struct bfd *nbfd ATTRIBUTE_UNUSED,
			    void *stream, void *buf, file_ptr nbytes,
			    file_ptr offset)
{
  FILE* file = (FILE*) stream;

  if (fseek(file, offset, SEEK_SET) != 0)
    die ("fseek error");

  return fread (buf, 1, nbytes, file);
}

static int
iovec_stat (struct bfd *abfd ATTRIBUTE_UNUSED, 
	    void *stream, struct stat *sb)
{
  return fstat (fileno ((FILE*) stream), sb);
}

static bool
check_format_any (struct bfd *abfd, bfd_format format)
{
  char** targets = NULL;

  if (bfd_check_format_matches (abfd, format, &targets))
    return true;

  if (targets)
    {
      bfd_find_target (targets[0], abfd);

      return bfd_check_format (abfd, format);
    }

  return false;
}

int
main (int argc, const char** argv)
{
  FILE* file;
  bfd *abfd, *mbfd;

  if (argc < 2)
    die ("Usage: test archivefile");

  file = fopen(argv[1], "rb");
  if (!file)
    die ("file not found");

  abfd = bfd_openr_iovec (argv[1], 0, iovec_open, file,
			  iovec_read, NULL, iovec_stat);
  if (!abfd)
    die ("error opening file");

  if (!check_format_any (abfd, bfd_archive))
    die ("not an archive");

  mbfd = bfd_openr_next_archived_file (abfd, 0);
  if (!mbfd)
    die ("error opening archive member");

  if (!bfd_close (mbfd))
    die ("error closing archive member");

  if (!bfd_close (abfd))
    die ("error closing archive");

  return 0;
}