/* Software floating-point emulation.
   Convert a 32bit unsigned integer to IEEE half.
 */

#include "soft-fp.h"
#include "half.h"

HFtype
__floatunsihf (USItype i)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  HFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_H (A, i, SI_BITS, USItype);
  FP_PACK_RAW_H (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
