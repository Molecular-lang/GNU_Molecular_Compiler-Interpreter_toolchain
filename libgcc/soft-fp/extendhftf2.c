/* Software floating-point emulation.
   Return an IEEE half converted to IEEE quad
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "half.h"
#include "quad.h"

TFtype
__extendhftf2 (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_Q (R);
  TFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_EXTEND (Q, H, 4, 1, R, A);
#else
  FP_EXTEND (Q, H, 2, 1, R, A);
#endif
  FP_PACK_RAW_Q (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
