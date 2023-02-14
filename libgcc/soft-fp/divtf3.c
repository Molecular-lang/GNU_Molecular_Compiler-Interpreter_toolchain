/* Software floating-point emulation.
   Return a / b
 */

#include "soft-fp.h"
#include "quad.h"

TFtype
__divtf3 (TFtype a, TFtype b)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_Q (B);
  FP_DECL_Q (R);
  TFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_Q (A, a);
  FP_UNPACK_Q (B, b);
  FP_DIV_Q (R, A, B);
  FP_PACK_Q (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
