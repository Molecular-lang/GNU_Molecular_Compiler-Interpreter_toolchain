/* Software floating-point emulation.
   Truncate IEEE double into bfloat16.
 */

#include "soft-fp.h"
#include "brain.h"
#include "double.h"

BFtype
__truncdfbf2 (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_B (R);
  BFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_D (A, a);
#if _FP_W_TYPE_SIZE < _FP_FRACBITS_D
  FP_TRUNC (B, D, 1, 2, R, A);
#else
  FP_TRUNC (B, D, 1, 1, R, A);
#endif
  FP_PACK_SEMIRAW_B (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
