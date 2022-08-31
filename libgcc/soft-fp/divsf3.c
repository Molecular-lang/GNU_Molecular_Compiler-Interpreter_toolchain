/* Software floating-point emulation.
   Return a / b
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "single.h"

SFtype
__divsf3 (SFtype a, SFtype b)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_S (B);
  FP_DECL_S (R);
  SFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_S (A, a);
  FP_UNPACK_S (B, b);
  FP_DIV_S (R, A, B);
  FP_PACK_S (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
