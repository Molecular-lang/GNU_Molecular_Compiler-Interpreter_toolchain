/* Software floating-point emulation.
   Convert a to 32bit unsigned integer
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

USItype
__fixunstfsi (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  USItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_TO_INT_Q (r, A, SI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
