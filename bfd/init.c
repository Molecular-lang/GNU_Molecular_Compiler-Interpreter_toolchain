/* bfd initialization stuff
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

/*
SECTION
	Initialization

SUBSECTION
	Initialization functions

	These are the functions that handle initializing a BFD.
*/

/*
FUNCTION
	bfd_init

SYNOPSIS
	unsigned int bfd_init (void);

DESCRIPTION
	This routine must be called before any other BFD function to
	initialize magical internal data structures.
	Returns a magic number, which may be used to check
	that the bfd library is configured as expected by users.
.
.{* Value returned by bfd_init.  *}
.
.#define BFD_INIT_MAGIC (sizeof (struct bfd_section))
*/

/* Actually, there is currently nothing for this function to do.
   However, someday it may be needed, so keep it around.  */

unsigned int
bfd_init (void)
{
  return BFD_INIT_MAGIC;
}
