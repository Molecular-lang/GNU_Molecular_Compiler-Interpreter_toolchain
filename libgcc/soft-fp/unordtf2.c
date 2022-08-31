/* Software floating-point emulation.
   Return 1 iff a or b is a NaN, 0 otherwise.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

CMPtype
__unordtf2 (TFtype a, TFtype b)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_Q (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_UNPACK_RAW_Q (B, b);
  FP_CMP_UNORD_Q (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
