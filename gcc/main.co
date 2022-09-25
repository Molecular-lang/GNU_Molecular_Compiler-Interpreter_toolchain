/* main.c: defines main() for cc1, cc1plus, etc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "diagnostic-core.h"
#include "toplev.h"

int main (int argc, char **argv);

/* We define main() to call toplev::main(), which is defined in toplev.cc.
   We do this in a separate file in order to allow the language front-end
   to define a different main(), if it so desires.  */

int
main (int argc, char **argv)
{
  toplev toplev (NULL, /* external_timer */
		 true /* init_signals */);

  int r = toplev.main (argc, argv);

  if (flag_checking && !seen_error ())
    toplev.finalize ();

  return r;
}
