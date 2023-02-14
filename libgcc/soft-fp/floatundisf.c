/* Software floating-point emulation.
   Convert a 64bit unsigned integer to IEEE single
 */

#include "soft-fp.h"
#include "single.h"

SFtype
__floatundisf (UDItype i)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  SFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_S (A, i, DI_BITS, UDItype);
  FP_PACK_RAW_S (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
