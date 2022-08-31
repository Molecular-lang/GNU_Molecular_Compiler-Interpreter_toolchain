/* compress-debug.c - compress debug sections
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include <stdio.h>
#include <zlib.h>
#include "ansidecl.h"
#include "compress-debug.h"

/* Initialize the compression engine.  */

struct z_stream_s *
compress_init (void)
{
  static struct z_stream_s strm;

  strm.zalloc = NULL;
  strm.zfree = NULL;
  strm.opaque = NULL;
  deflateInit (&strm, Z_DEFAULT_COMPRESSION);
  return &strm;
}

/* Stream the contents of a frag to the compression engine.  Output
   from the engine goes into the current frag on the obstack.  */

int
compress_data (struct z_stream_s *strm, const char **next_in,
	       int *avail_in, char **next_out, int *avail_out)
{
  int out_size = 0;
  int x;

  strm->next_in = (Bytef *) (*next_in);
  strm->avail_in = *avail_in;
  strm->next_out = (Bytef *) (*next_out);
  strm->avail_out = *avail_out;

  x = deflate (strm, Z_NO_FLUSH);
  if (x != Z_OK)
    return -1;

  out_size = *avail_out - strm->avail_out;
  *next_in = (char *) (strm->next_in);
  *avail_in = strm->avail_in;
  *next_out = (char *) (strm->next_out);
  *avail_out = strm->avail_out;

  return out_size;
}

/* Finish the compression and consume the remaining compressed output.
   Returns -1 for error, 0 when done, 1 when more output buffer is
   needed.  */

int
compress_finish (struct z_stream_s *strm, char **next_out,
		 int *avail_out, int *out_size)
{
  int x;

  strm->avail_in = 0;
  strm->next_out = (Bytef *) (*next_out);
  strm->avail_out = *avail_out;

  x = deflate (strm, Z_FINISH);

  *out_size = *avail_out - strm->avail_out;
  *next_out = (char *) (strm->next_out);
  *avail_out = strm->avail_out;

  if (x == Z_STREAM_END)
    {
      deflateEnd (strm);
      return 0;
    }
  if (strm->avail_out != 0)
    return -1;
  return 1;
}
