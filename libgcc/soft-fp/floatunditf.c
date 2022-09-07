/* Software floating-point emulation.
   Convert a 64bit unsigned integer to IEEE quad
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define FP_NO_EXCEPTIONS
#include "soft-fp.h"
#include "quad.h"

TFtype
__floatunditf (UDItype i)
{
  FP_DECL_Q (A);
  TFtype a;

  FP_FROM_INT_Q (A, i, DI_BITS, UDItype);
  FP_PACK_RAW_Q (a, A);

  return a;
}
