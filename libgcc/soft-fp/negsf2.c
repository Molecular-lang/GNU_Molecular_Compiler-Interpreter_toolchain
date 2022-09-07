/* Software floating-point emulation.
   Return -a
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "single.h"

SFtype
__negsf2 (SFtype a)
{
  FP_DECL_S (A);
  FP_DECL_S (R);
  SFtype r;

  FP_UNPACK_RAW_S (A, a);
  FP_NEG_S (R, A);
  FP_PACK_RAW_S (r, R);

  return r;
}
