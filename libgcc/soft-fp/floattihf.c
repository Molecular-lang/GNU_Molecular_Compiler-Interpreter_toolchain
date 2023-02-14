/* Software floating-point emulation.
   Convert a 128bit signed integer to IEEE half
 */

#include "soft-fp.h"
#include "half.h"

HFtype
__floattihf (TItype i)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  HFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_H (A, i, TI_BITS, UTItype);
  FP_PACK_RAW_H (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
