/* Software floating-point emulation.
   Truncate IEEE quad into IEEE double
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "double.h"
#include "quad.h"

DFtype
__trunctfdf2 (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_D (R);
  DFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_Q (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_TRUNC (D, Q, 2, 4, R, A);
#else
  FP_TRUNC (D, Q, 1, 2, R, A);
#endif
  FP_PACK_SEMIRAW_D (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
