/* Software floating-point emulation.
   Convert a 128bit unsigned integer to IEEE single
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "single.h"

SFtype
__floatuntisf (UTItype i)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  SFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_S (A, i, TI_BITS, UTItype);
  FP_PACK_RAW_S (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
