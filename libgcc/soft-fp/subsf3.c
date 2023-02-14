/* Software floating-point emulation.
   Return a - b
 */

#include "soft-fp.h"
#include "single.h"

SFtype
__subsf3 (SFtype a, SFtype b)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_S (B);
  FP_DECL_S (R);
  SFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_S (A, a);
  FP_UNPACK_SEMIRAW_S (B, b);
  FP_SUB_S (R, A, B);
  FP_PACK_SEMIRAW_S (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
