/* "main" for the compiler driver.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This source file contains "main" for the compiler driver.
   All of the real work is done within gcc.cc; we implement "main"
   in here for the "gcc" binary so that gcc.o can be used in
   libgccjit.so.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "xregex.h"
#include "obstack.h"
#include "intl.h"
#include "prefix.h"
#include "opt-suggestions.h"
#include "gcc.h"

/* Implement the top-level "main" within the driver in terms of
   driver::main (implemented in gcc.cc).  */

extern int main (int, char **);

int
main (int argc, char **argv)
{
  driver d (false, /* can_finalize */
	    false); /* debug */

  return d.main (argc, argv);
}
