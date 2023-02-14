/* ldver.c -- Print linker version. */

#include "sysdep.h"
#include "bfd.h"
#include "bfdver.h"
#include "bfdlink.h"
#include "ctf-api.h"
#include "ld.h"
#include "ldver.h"
#include "ldexp.h"
#include "ldlang.h"
#include "ldfile.h"
#include "ldemul.h"
#include "ldmain.h"

void
ldversion (int noisy)
{
  /* Output for noisy == 2 is intended to follow the GNU standards.  */
  fprintf (stdout, _("GNU ld %s\n"), BFD_VERSION_STRING);

  if (noisy & 2)
    {
      printf (_("Copyright (C) 2022 Free Software Foundation, Inc.\n"));
      printf (_("\
This program is free software; you may redistribute it under the terms of\n\
the GNU General Public License version 3 or (at your option) a later version.\n\
This program has absolutely no warranty.\n"));
    }

  if (noisy & 1)
    {
      ld_emulation_xfer_type **ptr = ld_emulations;

      printf (_("  Supported emulations:\n"));
      while (*ptr)
	{
	  printf ("   %s\n", (*ptr)->emulation_name);
	  ptr++;
	}
    }
}
