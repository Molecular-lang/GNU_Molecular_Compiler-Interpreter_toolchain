/* Configuration for GCC for hosting on Windows32.
   using GNU tools and the Windows32 API Library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define HOST_EXECUTABLE_SUFFIX ".exe"

#undef PATH_SEPARATOR
#define PATH_SEPARATOR ';'

/* This is the name of the null device on windows.  */
#define HOST_BIT_BUCKET "nul"

/*  The st_ino field of struct stat is always 0.  */
#define HOST_LACKS_INODE_NUMBERS

#ifdef __MINGW32__
#undef __USE_MINGW_ANSI_STDIO
#define __USE_MINGW_ANSI_STDIO 1
#else
/* MSVCRT does not support the "ll" format specifier for printing
   "long long" values.  Instead, we use "I64".  */
#define HOST_LONG_LONG_FORMAT "I64"
#endif
