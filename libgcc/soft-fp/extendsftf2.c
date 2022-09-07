/* Software floating-point emulation.
   Return a converted to IEEE quad
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "single.h"
#include "quad.h"

TFtype
__extendsftf2 (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_Q (R);
  TFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_EXTEND (Q, S, 4, 1, R, A);
#else
  FP_EXTEND (Q, S, 2, 1, R, A);
#endif
  FP_PACK_RAW_Q (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
