/* Generate checksums of executables for PCH validation
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bconfig.h"
#include "system.h"
#include "md5.h"

static void
usage (void)
{
  fputs ("Usage: genchecksums <filename> ...\n", stderr);
}

/* Important: BLOCKSIZE must be a multiple of 64.  */
#define BLOCKSIZE 4096

static void
dosum (struct md5_ctx *ctx, const char *file)
{
  FILE *f;
  char buffer[BLOCKSIZE + 72];
  size_t sum;

  f = fopen (file, "rb");
  if (!f)
    {
      fprintf (stderr, "opening %s: %s\n", file, xstrerror (errno));
      exit (1);
    }

  /* Some executable formats have timestamps in the first 16 bytes, yuck.  */
  if (fseek (f, 16, SEEK_SET) != 0)
     {
      fprintf (stderr, "seeking in %s: %s\n", file, xstrerror (errno));
      exit (1);
    }

  /* Iterate over full file contents.  */
  while (1)
    {
      /* We read the file in blocks of BLOCKSIZE bytes.  One call of the
	 computation function processes the whole buffer so that with the
	 next round of the loop another block can be read.  */
      size_t n;
      sum = 0;

      /* Read block.  Take care for partial reads.  */
      do
	{
	  n = fread (buffer + sum, 1, BLOCKSIZE - sum, f);

	  sum += n;
	}
      while (sum < BLOCKSIZE && n != 0);
      if (n == 0 && ferror (f))
        exit (1);

      /* If end of file is reached, end the loop.  */
      if (n == 0)
	break;

      /* Process buffer with BLOCKSIZE bytes.  Note that
			BLOCKSIZE % 64 == 0
       */
      md5_process_block (buffer, BLOCKSIZE, ctx);
    }

  /* Add the last bytes if necessary.  */
  if (sum > 0)
    md5_process_bytes (buffer, sum, ctx);

  if (fclose (f) != 0)
     {
      fprintf (stderr, "reading %s: %s\n", file, xstrerror (errno));
      exit (1);
    }
}

int
main (int argc, char ** argv)
{
  struct md5_ctx ctx;
  unsigned char result[16];
  int i;

  if (argc < 2)
    {
      usage ();
      return 1;
    }

  md5_init_ctx (&ctx);
  for (i = 1; i < argc; i++) 
    dosum (&ctx, argv[i]);
  md5_finish_ctx (&ctx, result);

  puts ("#include \"config.h\"");
  puts ("#include \"system.h\"");
  fputs ("EXPORTED_CONST unsigned char executable_checksum[16] = { ", stdout);
  for (i = 0; i < 16; i++)
    printf ("0x%02x%s", result[i], i == 15 ? " };\n" : ", ");

  return 0;
}
