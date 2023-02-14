/* Software floating-point emulation.
   Truncate IEEE extended into bfloat16.
 */

#include "soft-fp.h"
#include "brain.h"
#include "extended.h"

BFtype __truncxfbf2(XFtype a)
{
  FP_DECL_EX;
  FP_DECL_E (A);
  FP_DECL_B (R);
  BFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_E (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_TRUNC (B, E, 1, 4, R, A);
#else
  FP_TRUNC (B, E, 1, 2, R, A);
#endif
  FP_PACK_SEMIRAW_B (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
