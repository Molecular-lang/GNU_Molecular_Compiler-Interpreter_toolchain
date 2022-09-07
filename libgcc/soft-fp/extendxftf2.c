/* Software floating-point emulation.
   Return a converted to IEEE quad
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "extended.h"
#include "quad.h"

TFtype
__extendxftf2 (XFtype a)
{
  FP_DECL_EX;
  FP_DECL_E (A);
  FP_DECL_Q (R);
  TFtype r;

  FP_INIT_TRAPPING_EXCEPTIONS;
  FP_UNPACK_RAW_E (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_EXTEND (Q, E, 4, 4, R, A);
#else
  FP_EXTEND (Q, E, 2, 2, R, A);
#endif
  FP_PACK_RAW_Q (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
