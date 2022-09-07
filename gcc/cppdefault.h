/* CPP Library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CPPDEFAULT_H
#define GCC_CPPDEFAULT_H

/* This is the default list of directories to search for include files.
   It may be overridden by the various -I and -ixxx options.

   #include "file" looks in the same directory as the current file,
   then this list.
   #include <file> just looks in this list.

   All these directories are treated as `system' include directories
   (they are not subject to pedantic warnings in some cases).  */

struct default_include
{
  const char *const fname;	/* The name of the directory.  */
  const char *const component;	/* The component containing the directory
				   (see update_path in prefix.cc) */
  const char cplusplus;		/* When this is non-zero, we should only
				   consider this if we're compiling C++.
				   When the -stdlib option is configured, this
				   may take values greater than 1 to indicate
				   which C++ standard library should be
				   used.  */
  const char cxx_aware;		/* Includes in this directory don't need to
				   be wrapped in extern "C" when compiling
				   C++.  */
  const char add_sysroot;	/* FNAME should be prefixed by
				   cpp_SYSROOT.  */
  const char multilib;		/* FNAME should have appended
				   - the multilib path specified with -imultilib
				     when set to 1,
				   - the multiarch path specified with
				     -imultiarch, when set to 2.  */
};

extern const struct default_include cpp_include_defaults[];
extern const char cpp_GCC_INCLUDE_DIR[];
extern const size_t cpp_GCC_INCLUDE_DIR_len;

/* The configure-time prefix, i.e., the value supplied as the argument
   to --prefix=.  */
extern const char cpp_PREFIX[];
/* The length of the configure-time prefix.  */
extern const size_t cpp_PREFIX_len;
/* The configure-time execution prefix.  This is typically the lib/gcc
   subdirectory of cpp_PREFIX.  */
extern const char cpp_EXEC_PREFIX[];
/* The run-time execution prefix.  This is typically the lib/gcc
   subdirectory of the actual installation.  */
extern const char *gcc_exec_prefix;

/* Return true if the toolchain is relocated.  */
bool cpp_relocated (void);

#endif /* ! GCC_CPPDEFAULT_H */
