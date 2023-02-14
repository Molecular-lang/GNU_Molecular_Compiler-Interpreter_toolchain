/* Software floating-point emulation.
   Convert a 32bit signed integer to IEEE quad
 */

#define FP_NO_EXCEPTIONS
#include "soft-fp.h"
#include "quad.h"

TFtype
__floatsitf (SItype i)
{
  FP_DECL_Q (A);
  TFtype a;

  FP_FROM_INT_Q (A, i, SI_BITS, USItype);
  FP_PACK_RAW_Q (a, A);

  return a;
}
