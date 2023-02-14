/* Software floating-point emulation.
   Return 0 iff a == b, 1 otherwise
 */

#include "soft-fp.h"
#include "quad.h"

CMPtype
__eqtf2 (TFtype a, TFtype b)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_Q (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_UNPACK_RAW_Q (B, b);
  FP_CMP_EQ_Q (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}

strong_alias (__eqtf2, __netf2);
