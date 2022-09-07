/* Define builtin-in macros for all front ends that perform preprocessing
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CPPBUILTIN_H
#define GCC_CPPBUILTIN_H

/* Parse a BASEVER version string of the format "major.minor.patchlevel"
   or "major.minor" to extract its components.  */
extern void parse_basever (int *, int *, int *);

/* Define macros builtins common to all language performing CPP
   preprocessing.  */
extern void define_language_independent_builtin_macros (cpp_reader *);


#endif /* ! GCC_CPPBUILTIN_H */

