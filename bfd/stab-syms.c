/* Table of stab names for the BFD library.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"

#define ARCH_SIZE 32		/* Value doesn't matter.  */
#include "libaout.h"
#include "aout/aout64.h"

/* Ignore duplicate stab codes; just return the string for the first
   one.  */
#define __define_stab(NAME, CODE, STRING) __define_name(CODE, STRING)
#define __define_stab_duplicate(NAME, CODE, STRING)

/* These are not really stab symbols, but it is
   convenient to have them here for the sake of nm.
   For completeness, we could also add N_TEXT etc, but those
   are never needed, since nm treats those specially.  */
#define EXTRA_SYMBOLS \
  __define_name (N_SETA, "SETA")/* Absolute set element symbol */ \
  __define_name (N_SETT, "SETT")/* Text set element symbol */ \
  __define_name (N_SETD, "SETD")/* Data set element symbol */ \
  __define_name (N_SETB, "SETB")/* Bss set element symbol */ \
  __define_name (N_SETV, "SETV")/* Pointer to set vector in data area.  */ \
  __define_name (N_INDR, "INDR") \
  __define_name (N_WARNING, "WARNING")

const char *
bfd_get_stab_name (int code)
{
  switch (code)
    {
#define __define_name(val, str) case val: return str;
#include "aout/stab.def"
      EXTRA_SYMBOLS
    }

  return (const char *) 0;
}
