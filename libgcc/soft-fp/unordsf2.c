/* Software floating-point emulation.
   Return 1 iff a or b is a NaN, 0 otherwise.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "single.h"

CMPtype
__unordsf2 (SFtype a, SFtype b)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_S (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
  FP_UNPACK_RAW_S (B, b);
  FP_CMP_UNORD_S (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
