/* Software floating-point emulation.
   Truncate IEEE double into IEEE half.
 */

#include "soft-fp.h"
#include "half.h"
#include "double.h"

HFtype
__truncdfhf2 (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_H (R);
  HFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_D (A, a);
#if _FP_W_TYPE_SIZE < _FP_FRACBITS_D
  FP_TRUNC (H, D, 1, 2, R, A);
#else
  FP_TRUNC (H, D, 1, 1, R, A);
#endif
  FP_PACK_SEMIRAW_H (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
