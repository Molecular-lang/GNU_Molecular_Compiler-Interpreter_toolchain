/* Software floating-point emulation.
   Truncate IEEE single into bfloat16.
 */

#include "soft-fp.h"
#include "brain.h"
#include "single.h"

BFtype
__truncsfbf2 (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_B (R);
  BFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_S (A, a);
  FP_TRUNC (B, S, 1, 1, R, A);
  FP_PACK_SEMIRAW_B (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
