/* Software floating-point emulation.
   Truncate bfloat16 into IEEE half.
 */

#include "soft-fp.h"
#include "half.h"
#include "brain.h"
#include "single.h"

/* BFtype and HFtype are unordered, neither is a superset or subset
   of each other.  Convert BFtype to SFtype (lossless) and then
   truncate to HFtype.  */

HFtype
__truncbfhf2 (BFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_S (B);
  FP_DECL_B (R);
  SFtype b;
  HFtype r;

  FP_INIT_ROUNDMODE;
  /* Optimize BFtype to SFtype conversion to simple left shift
     by 16 if possible, we don't need to raise exceptions on sNaN
     here as the SFtype to HFtype truncation should do that too.  */
  if (sizeof (BFtype) == 2
      && sizeof (unsigned short) == 2
      && sizeof (SFtype) == 4
      && sizeof (unsigned int) == 4)
    {
      union { BFtype a; unsigned short b; } u1;
      union { SFtype a; unsigned int b; } u2;
      u1.a = a;
      u2.b = (u1.b << 8) << 8;
      b = u2.a;
    }
  else
    {
      FP_UNPACK_RAW_B (A, a);
      FP_EXTEND (S, B, 1, 1, B, A);
      FP_PACK_RAW_S (b, B);
    }
  FP_UNPACK_SEMIRAW_S (B, b);
  FP_TRUNC (H, S, 1, 1, R, B);
  FP_PACK_SEMIRAW_H (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
