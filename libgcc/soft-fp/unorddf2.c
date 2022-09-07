/* Software floating-point emulation.
   Return 1 iff a or b is a NaN, 0 otherwise.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "double.h"

CMPtype
__unorddf2 (DFtype a, DFtype b)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_D (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_UNPACK_RAW_D (B, b);
  FP_CMP_UNORD_D (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
