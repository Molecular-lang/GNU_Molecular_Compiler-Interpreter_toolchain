/* Software floating-point emulation.
   Convert a 64bit signed integer to IEEE half
 */

#include "soft-fp.h"
#include "half.h"

HFtype
__floatdihf (DItype i)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  HFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_H (A, i, DI_BITS, UDItype);
  FP_PACK_RAW_H (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
