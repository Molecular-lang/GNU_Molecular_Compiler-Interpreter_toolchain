/* Software floating-point emulation.
   Convert IEEE single to 128bit signed integer
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "single.h"

TItype
__fixsfti (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  UTItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
  FP_TO_INT_S (r, A, TI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
