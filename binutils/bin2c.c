/* bin2c.c -- dump binary file in hex format
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <stdio.h>
#include <stdlib.h>
#include "binary-io.h"

int
main (int argc, char *argv[])
{
  int c;
  int i;

  if (argc != 1)
    {
      int ishelp = 0;
      FILE *stream;

      if (argc == 2 && argv[1][0] == '-')
	{
	  const char *opt = &argv[1][1];
	  if (*opt == '-')
	    ++opt;
	  ishelp = *opt == 'h' || *opt == 'H';
	}

      stream = ishelp ? stdout : stderr;
      fprintf (stream, "Usage: %s < input_file > output_file\n", argv[0]);
      fprintf (stream, "Prints bytes from stdin in hex format.\n");
      exit (!ishelp);
    }

  SET_BINARY (fileno (stdin));

  i = 0;
  while ((c = getc (stdin)) != EOF)
    {
      printf ("0x%02x,", c);
      if (++i == 16)
	{
	  printf ("\n");
	  i = 0;
	}
    }
  if (i != 0)
    printf ("\n");

  exit (0);
}
