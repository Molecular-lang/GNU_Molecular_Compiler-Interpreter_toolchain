/* Software floating-point emulation.
   Truncate IEEE extended into IEEE half.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "half.h"
#include "extended.h"

HFtype
__truncxfhf2 (XFtype a)
{
  FP_DECL_EX;
  FP_DECL_E (A);
  FP_DECL_H (R);
  HFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_E (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_TRUNC (H, E, 1, 4, R, A);
#else
  FP_TRUNC (H, E, 1, 2, R, A);
#endif
  FP_PACK_SEMIRAW_H (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
