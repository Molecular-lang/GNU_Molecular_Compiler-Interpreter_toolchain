/* Software floating-point emulation.
   Convert a 128bit signed integer to IEEE quad
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

TFtype
__floattitf (TItype i)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  TFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_Q (A, i, TI_BITS, UTItype);
  FP_PACK_RAW_Q (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
