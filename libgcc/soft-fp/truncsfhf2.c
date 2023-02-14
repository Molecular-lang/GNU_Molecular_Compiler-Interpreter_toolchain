/* Software floating-point emulation.
   Truncate IEEE single into IEEE half.
 */

#include "soft-fp.h"
#include "half.h"
#include "single.h"

HFtype
__truncsfhf2 (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_H (R);
  HFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_S (A, a);
  FP_TRUNC (H, S, 1, 1, R, A);
  FP_PACK_SEMIRAW_H (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
