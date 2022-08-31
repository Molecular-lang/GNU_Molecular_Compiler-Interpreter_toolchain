/* GCOV interface routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GCOV_H
#define GCC_GCOV_H

struct gcov_info;

/* Set all counters to zero.  */

extern void __gcov_reset (void);

/* Write profile information to a file.  */

extern void __gcov_dump (void);

/* Convert the gcov information referenced by INFO to a gcda data stream.
   The FILENAME_FN callback is called exactly once with the filename associated
   with the gcov information.  The filename may be NULL.  Afterwards, the
   DUMP_FN callback is subsequently called with chunks (the begin and length of
   the chunk are passed as the first two callback parameters) of the gcda data
   stream.  The ALLOCATE_FN callback shall allocate memory with a size in
   characters specified by the first callback parameter.  The ARG parameter is
   a user-provided argument passed as the last argument to the callback
   functions.  It is recommended to use the __gcov_filename_to_gcfn()
   in the filename callback function.  */

extern void
__gcov_info_to_gcda (const struct gcov_info *__info,
		     void (*__filename_fn) (const char *, void *),
		     void (*__dump_fn) (const void *, unsigned, void *),
		     void *(*__allocate_fn) (unsigned, void *),
		     void *__arg);

/* Convert the FILENAME to a gcfn data stream.  The DUMP_FN callback is
   subsequently called with chunks (the begin and length of the chunk are
   passed as the first two callback parameters) of the gcfn data stream.
   The ARG parameter is a user-provided argument passed as the last
   argument to the DUMP_FN callback function.  This function is intended
   to be used by the filename callback of __gcov_info_to_gcda().  The gcfn
   data stream is used by the merge-stream subcommand of the gcov-tool to
   get the filename associated with a gcda data stream.  */

extern void
__gcov_filename_to_gcfn (const char *__filename,
			 void (*__dump_fn) (const void *, unsigned, void *),
			 void *__arg);

#endif /* GCC_GCOV_H */
