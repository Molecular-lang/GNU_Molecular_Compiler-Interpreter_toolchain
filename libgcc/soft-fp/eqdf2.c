/* Software floating-point emulation.
   Return 0 iff a == b, 1 otherwise
 */

#include "soft-fp.h"
#include "double.h"

CMPtype
__eqdf2 (DFtype a, DFtype b)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_D (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_UNPACK_RAW_D (B, b);
  FP_CMP_EQ_D (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}

strong_alias (__eqdf2, __nedf2);
