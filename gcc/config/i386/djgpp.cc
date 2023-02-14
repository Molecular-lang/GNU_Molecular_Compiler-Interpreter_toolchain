/* Subroutines for DJGPP. */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "output.h"
#include "lto-section-names.h"

void
i386_djgpp_asm_named_section(const char *name, unsigned int flags,
			     tree)
{
  char flagchars[8], *f = flagchars;

  if (flags & SECTION_WRITE)
    *f++ = 'w';
  if (flags & SECTION_CODE)
    *f++ = 'x';

  /* LTO sections need 1-byte alignment to avoid confusing the
     zlib decompression algorithm with trailing zero pad bytes.  */
  if (strncmp (name, LTO_SECTION_NAME_PREFIX,
			strlen (LTO_SECTION_NAME_PREFIX)) == 0)
    *f++ = '0';

  *f++ = '\0';

  fprintf (asm_out_file, "\t.section\t%s,\"%s\"\n", name, flagchars);
}

/* Kludge because of missing COFF support for early LTO debug.  */

static enum debug_info_levels saved_debug_info_level;

void
i386_djgpp_asm_lto_start (void)
{
  saved_debug_info_level = debug_info_level;
  debug_info_level = DINFO_LEVEL_NONE;
}

void
i386_djgpp_asm_lto_end (void)
{
  debug_info_level = saved_debug_info_level;
}
