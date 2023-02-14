/* Software floating-point emulation.
   Return 0 iff a == b, 1 otherwise
 */

#include "soft-fp.h"
#include "single.h"

CMPtype
__eqsf2 (SFtype a, SFtype b)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_S (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
  FP_UNPACK_RAW_S (B, b);
  FP_CMP_EQ_S (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}

strong_alias (__eqsf2, __nesf2);
