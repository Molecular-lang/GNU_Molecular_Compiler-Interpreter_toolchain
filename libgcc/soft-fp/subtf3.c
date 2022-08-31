/* Software floating-point emulation.
   Return a - b
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

TFtype
__subtf3 (TFtype a, TFtype b)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_Q (B);
  FP_DECL_Q (R);
  TFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_Q (A, a);
  FP_UNPACK_SEMIRAW_Q (B, b);
  FP_SUB_Q (R, A, B);
  FP_PACK_SEMIRAW_Q (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
