/* compress-debug.h - Header file for compressed debug sections.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef COMPRESS_DEBUG_H
#define COMPRESS_DEBUG_H

struct z_stream_s;

/* Initialize the compression engine.  */
extern struct z_stream_s *
compress_init (void);

/* Stream the contents of a frag to the compression engine.  Output
   from the engine goes into the current frag on the obstack.  */
extern int
compress_data (struct z_stream_s *, const char **, int *, char **, int *);

/* Finish the compression and consume the remaining compressed output.  */
extern int
compress_finish (struct z_stream_s *, char **, int *, int *);

#endif /* COMPRESS_DEBUG_H */
