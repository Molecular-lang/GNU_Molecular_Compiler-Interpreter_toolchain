/* Generate code from machine description to recognize rtl as insns.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This program is used to produce tmp-mddump.md, which represents
   md-file with expanded iterators and after define_subst transformation
   is performed.

   The only argument of the program is a source md-file (e.g.
   config/i386/i386.md).  STDERR is used for the program output.  */

#include "bconfig.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "errors.h"
#include "read-md.h"
#include "gensupport.h"

extern int main (int, const char **);

int
main (int argc, const char **argv)
{
  progname = "genmddump";

  if (!init_rtx_reader_args (argc, argv))
    return (FATAL_EXIT_CODE);

  /* Read the machine description.  */
  md_rtx_info info;
  while (read_md_rtx (&info))
    {
      printf (";; %s: %d\n", info.loc.filename, info.loc.lineno);
      print_inline_rtx (stdout, info.def, 0);
      printf ("\n\n");
    }

  fflush (stdout);
  return (ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE);
}
