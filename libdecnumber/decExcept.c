/* Temporary library support for decimal floating point.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <fenv.h>
#include "dconfig.h"
#include "decContext.h"
#include "decExcept.h"

/* Internal, non-documented functions for testing libgcc functions.
   This support is not sufficient for real use.  */

static int __dfp_except_flags = 0;

/* Clear the dummy exception flags.  */
void
__dfp_clear_except (void)
{
  __dfp_except_flags = 0;
}

/* Return the dummy exception flags corresponding to the mask.  */
int
__dfp_test_except (int mask)
{
  return __dfp_except_flags & mask;
}

/* Set dummy exception flags.  */
void
__dfp_raise_except (int flags)
{
  __dfp_except_flags |= flags;
}
