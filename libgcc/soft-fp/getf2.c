/* Software floating-point emulation.
   Return 0 iff a == b, 1 iff a > b, -2 iff a ? b, -1 iff a < b
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

CMPtype
__getf2 (TFtype a, TFtype b)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_Q (B);
  CMPtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_UNPACK_RAW_Q (B, b);
  FP_CMP_Q (r, A, B, -2, 2);
  FP_HANDLE_EXCEPTIONS;

  return r;
}

strong_alias (__getf2, __gttf2);
