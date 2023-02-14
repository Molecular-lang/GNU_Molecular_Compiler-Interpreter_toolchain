/* Software floating-point emulation.
   Return an IEEE half converted to IEEE single
 */

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "half.h"
#include "single.h"

SFtype
__extendhfsf2 (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_S (R);
  SFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
  FP_EXTEND (S, H, 1, 1, R, A);
  FP_PACK_RAW_S (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
