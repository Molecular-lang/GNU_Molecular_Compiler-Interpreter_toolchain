/* Software floating-point emulation.
   Return -a
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

TFtype
__negtf2 (TFtype a)
{
  FP_DECL_Q (A);
  FP_DECL_Q (R);
  TFtype r;

  FP_UNPACK_RAW_Q (A, a);
  FP_NEG_Q (R, A);
  FP_PACK_RAW_Q (r, R);

  return r;
}
