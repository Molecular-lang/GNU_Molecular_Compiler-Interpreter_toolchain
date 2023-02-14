/* Software floating-point emulation.
   Return an bfloat16 converted to IEEE single
 */

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "brain.h"
#include "single.h"

SFtype
__extendbfsf2 (BFtype a)
{
  FP_DECL_EX;
  FP_DECL_B (A);
  FP_DECL_S (R);
  SFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_B (A, a);
  FP_EXTEND (S, B, 1, 1, R, A);
  FP_PACK_RAW_S (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
