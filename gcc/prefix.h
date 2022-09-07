/* Provide prototypes for functions exported from prefix.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_PREFIX_H
#define GCC_PREFIX_H

#ifdef __cplusplus
extern "C" {
#endif

/* These functions are called by the Ada frontend with C convention.  */

/* Update PATH using KEY if PATH starts with PREFIX.  The returned
   string is always malloc-ed, and the caller is responsible for
   freeing it.  */
extern char *update_path(const char *path, const char *key);
extern void set_std_prefix(const char *, int);

#ifdef __cplusplus
}
#endif

#endif /* ! GCC_PREFIX_H */
