/* Software floating-point emulation.
   Convert a to 32bit signed integer
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

SItype
__fixtfsi (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  USItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_TO_INT_Q (r, A, SI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
