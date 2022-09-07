/* Declarations and definitons for stringpool.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_STRINGPOOL_H
#define GCC_STRINGPOOL_H

/* Return the (unique) IDENTIFIER_NODE node for a given name.
   The name is supplied as a char *.  */
extern tree get_identifier (const char *);

/* If an identifier with the name TEXT (a null-terminated string) has
   previously been referred to, return that node; otherwise return
   NULL_TREE.  */
extern tree maybe_get_identifier (const char *);

/* Identical to get_identifier, except that the length is assumed
   known.  */
extern tree get_identifier_with_length (const char *, size_t);

#if GCC_VERSION >= 3000
#define get_identifier(str) \
  (__builtin_constant_p (str)				\
    ? get_identifier_with_length ((str), strlen (str))  \
    : get_identifier (str))
#endif

#endif  // GCC_STRINGPOOL_H
