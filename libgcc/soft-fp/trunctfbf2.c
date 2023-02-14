/* Software floating-point emulation.
   Truncate IEEE quad into bfloat16.
 */

#include "soft-fp.h"
#include "brain.h"
#include "quad.h"

BFtype
__trunctfbf2 (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_B (R);
  BFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_Q (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_TRUNC (B, Q, 1, 4, R, A);
#else
  FP_TRUNC (B, Q, 1, 2, R, A);
#endif
  FP_PACK_SEMIRAW_B (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
