/* Software floating-point emulation.
   Convert a 32bit unsigned integer to IEEE double
 */

#define FP_NO_EXCEPTIONS
#include "soft-fp.h"
#include "double.h"

DFtype
__floatunsidf (USItype i)
{
  FP_DECL_D (A);
  DFtype a;

  FP_FROM_INT_D (A, i, SI_BITS, USItype);
  FP_PACK_RAW_D (a, A);

  return a;
}
