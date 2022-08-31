/* Set up combined include path for the preprocessor.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_INCPATH_H
#define GCC_INCPATH_H

/* Various fragments of include path.  */
enum incpath_kind {
  INC_QUOTE = 0, /* include "foo" */
  INC_BRACKET,   /* include <foo> */
  INC_SYSTEM,    /* sys-include */
  INC_AFTER,	 /* post-sysinclude  */
  INC_MAX
};

extern void split_quote_chain (void);
extern void add_path (char *, incpath_kind, int, bool);
extern void register_include_chains (cpp_reader *, const char *,
				     const char *, const char *,
				     int, int, int);
extern void add_cpp_dir_path (struct cpp_dir *, incpath_kind);
extern struct cpp_dir *get_added_cpp_dirs (incpath_kind);

struct target_c_incpath_s {
  /* Do extra includes processing.  STDINC is false iff -nostdinc was given.  */
  void (*extra_pre_includes) (const char *, const char *, int);
  void (*extra_includes) (const char *, const char *, int);
};

extern struct target_c_incpath_s target_c_incpath;

#endif /* GCC_INCPATH_H */
