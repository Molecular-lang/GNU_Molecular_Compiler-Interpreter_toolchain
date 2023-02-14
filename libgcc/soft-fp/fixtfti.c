/* Software floating-point emulation.
   Convert IEEE quad to 128bit signed integer
 */

#include "soft-fp.h"
#include "quad.h"

TItype
__fixtfti (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  UTItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_TO_INT_Q (r, A, TI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
