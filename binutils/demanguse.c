/* demanguse.c -- libiberty demangler usage
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <stdio.h>
#include <string.h>
#include "demangle.h"
#include "demanguse.h"

/* Print the list of demangling styles to STREAM.  A one line MSG is
   printed before the styles.  Output is limited to 80 columns, with
   continuation lines being indented by leading spaces in MSG.  */

void
display_demangler_styles (FILE *stream, const char *msg)
{
  const struct demangler_engine *info = libiberty_demanglers;
  int col;
  int lead_spaces = 0;
  const char *cont = "";

  while (msg[lead_spaces] == ' ')
    ++lead_spaces;
  col = fprintf (stream, "%s", msg);
  while (info->demangling_style_name)
    {
      if (col + strlen (info->demangling_style_name) >= 75)
	{
	  fprintf (stream, "%.1s\n", cont);
	  col = fprintf (stream, "%.*s", lead_spaces, msg);
	  cont = "";
	}
      col += fprintf (stream, "%s\"%s\"", cont, info->demangling_style_name);
      cont = ", ";
      ++info;
    }
  fprintf (stream, "\n");
}
