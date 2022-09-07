/* Software floating-point emulation.
   Truncate IEEE quad into IEEE half.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "half.h"
#include "quad.h"

HFtype
__trunctfhf2 (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_H (R);
  HFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_Q (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_TRUNC (H, Q, 1, 4, R, A);
#else
  FP_TRUNC (H, Q, 1, 2, R, A);
#endif
  FP_PACK_SEMIRAW_H (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
