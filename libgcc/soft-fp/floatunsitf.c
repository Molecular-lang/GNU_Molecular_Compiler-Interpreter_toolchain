/* Software floating-point emulation.
   Convert a 32bit unsigned integer to IEEE quad
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define FP_NO_EXCEPTIONS
#include "soft-fp.h"
#include "quad.h"

TFtype
__floatunsitf (USItype i)
{
  FP_DECL_Q (A);
  TFtype a;

  FP_FROM_INT_Q (A, i, SI_BITS, USItype);
  FP_PACK_RAW_Q (a, A);

  return a;
}
