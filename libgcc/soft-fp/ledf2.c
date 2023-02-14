/* Software floating-point emulation.
   Return 0 iff a == b, 1 iff a > b, 2 iff a ? b, -1 iff a < b
 */

#include "soft-fp.h"
#include "double.h"

CMPtype
__ledf2 (DFtype a, DFtype b)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_D (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_UNPACK_RAW_D (B, b);
  FP_CMP_D (r, A, B, 2, 2);
  FP_HANDLE_EXCEPTIONS;

  return r;
}

strong_alias (__ledf2, __ltdf2);
