/* Software floating-point emulation.
   Convert a to 64bit signed integer
 */

#include "soft-fp.h"
#include "quad.h"

DItype
__fixtfdi (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  UDItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_TO_INT_Q (r, A, DI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
