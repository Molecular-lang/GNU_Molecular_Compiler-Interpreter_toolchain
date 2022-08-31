/* Libiberty basename.  Like basename, but is not overridden by the
   system C library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/*

@deftypefn Replacement {const char*} lbasename (const char *@var{name})

Given a pointer to a string containing a typical pathname
(@samp{/usr/src/cmd/ls/ls.c} for example), returns a pointer to the
last component of the pathname (@samp{ls.c} in this case).  The
returned pointer is guaranteed to lie within the original
string.  This latter fact is not true of many vendor C
libraries, which return special strings or modify the passed
strings for particular input.

In particular, the empty string returns the same empty string,
and a path ending in @code{/} returns the empty string after it.

@end deftypefn

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "ansidecl.h"
#include "libiberty.h"
#include "safe-ctype.h"
#include "filenames.h"

const char *
unix_lbasename (const char *name)
{
  const char *base;

  for (base = name; *name; name++)
    if (IS_UNIX_DIR_SEPARATOR (*name))
      base = name + 1;

  return base;
}

const char *
dos_lbasename (const char *name)
{
  const char *base;

  /* Skip over a possible disk name.  */
  if (ISALPHA (name[0]) && name[1] == ':') 
    name += 2;

  for (base = name; *name; name++)
    if (IS_DOS_DIR_SEPARATOR (*name))
      base = name + 1;

  return base;
}

const char *
lbasename (const char *name)
{
#if defined (HAVE_DOS_BASED_FILE_SYSTEM)
  return dos_lbasename (name);
#else
  return unix_lbasename (name);
#endif
}
