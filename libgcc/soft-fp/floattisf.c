/* Software floating-point emulation.
   Convert a 128bit signed integer to IEEE single
 */

#include "soft-fp.h"
#include "single.h"

SFtype
__floattisf (TItype i)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  SFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_S (A, i, TI_BITS, UTItype);
  FP_PACK_RAW_S (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
