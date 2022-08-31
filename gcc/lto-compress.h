/* LTO IL compression streams.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LTO_COMPRESS_H
#define GCC_LTO_COMPRESS_H

struct lto_compression_stream;

/* In lto-compress.cc.  */
extern struct lto_compression_stream
  *lto_start_compression (void (*callback) (const char *, unsigned, void *),
			  void *opaque);
extern void lto_compress_block (struct lto_compression_stream *stream,
				const char *base, size_t num_chars);
extern void lto_end_compression (struct lto_compression_stream *stream);

extern struct lto_compression_stream
  *lto_start_uncompression (void (*callback) (const char *, unsigned, void *),
			    void *opaque);
extern void lto_uncompress_block (struct lto_compression_stream *stream,
				  const char *base, size_t num_chars);
extern void lto_end_uncompression (struct lto_compression_stream *stream,
				  lto_compression compression);

#endif /* GCC_LTO_COMPRESS_H  */
