/* Software floating-point emulation.
   Convert a 32bit signed integer to IEEE double
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define FP_NO_EXCEPTIONS
#include "soft-fp.h"
#include "double.h"

DFtype
__floatsidf (SItype i)
{
  FP_DECL_D (A);
  DFtype a;

  FP_FROM_INT_D (A, i, SI_BITS, USItype);
  FP_PACK_RAW_D (a, A);

  return a;
}
