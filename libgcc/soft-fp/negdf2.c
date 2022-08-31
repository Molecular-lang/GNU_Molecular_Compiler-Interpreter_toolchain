/* Software floating-point emulation.
   Return -a
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "double.h"

DFtype
__negdf2 (DFtype a)
{
  FP_DECL_D (A);
  FP_DECL_D (R);
  DFtype r;

  FP_UNPACK_RAW_D (A, a);
  FP_NEG_D (R, A);
  FP_PACK_RAW_D (r, R);

  return r;
}
