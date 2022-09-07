/* Software floating-point emulation.
   Return 0 iff a == b, 1 otherwise
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "half.h"

CMPtype
__eqhf2 (HFtype a, HFtype b)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_H (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
  FP_UNPACK_RAW_H (B, b);
  FP_CMP_EQ_H (r, A, B, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}

strong_alias (__eqhf2, __nehf2);
