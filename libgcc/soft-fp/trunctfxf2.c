/* Software floating-point emulation.
   Truncate IEEE quad into IEEE extended
 */

#include "soft-fp.h"
#include "extended.h"
#include "quad.h"

XFtype
__trunctfxf2 (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_E (R);
  XFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_Q (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_TRUNC (E, Q, 4, 4, R, A);
#else
  FP_TRUNC (E, Q, 2, 2, R, A);
#endif
  FP_PACK_SEMIRAW_E (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
