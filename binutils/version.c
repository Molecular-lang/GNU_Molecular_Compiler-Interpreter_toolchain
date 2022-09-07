/* version.c -- binutils version information
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "sysdep.h"
#include "bfd.h"
#include "bucomm.h"

/* Print the version number and copyright information, and exit.
   This implements the --version option for the various programs.  */

void
print_version (const char *name)
{
  /* This output is intended to follow the GNU standards document.  */
  /* xgettext:c-format */
  printf ("GNU %s %s\n", name, BFD_VERSION_STRING);
  printf (_("Copyright (C) 2022 Free Software Foundation, Inc.\n"));
  printf (_("\
This program is free software; you may redistribute it under the terms of\n\
the GNU General Public License version 3 or (at your option) any later version.\n\
This program has absolutely no warranty.\n"));
  exit (0);
}
