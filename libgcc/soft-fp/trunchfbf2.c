/* Software floating-point emulation.
   Truncate IEEE half into bfloat16.
 */

#include "soft-fp.h"
#include "brain.h"
#include "half.h"
#include "single.h"

/* BFtype and HFtype are unordered, neither is a superset or subset
   of each other.  Convert HFtype to SFtype (lossless) and then
   truncate to BFtype.  */

BFtype
__trunchfbf2 (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_S (B);
  FP_DECL_B (R);
  SFtype b;
  BFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_RAW_H (A, a);
  FP_EXTEND (S, H, 1, 1, B, A);
  FP_PACK_RAW_S (b, B);
  FP_UNPACK_SEMIRAW_S (B, b);
  FP_TRUNC (B, S, 1, 1, R, B);
  FP_PACK_SEMIRAW_B (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
