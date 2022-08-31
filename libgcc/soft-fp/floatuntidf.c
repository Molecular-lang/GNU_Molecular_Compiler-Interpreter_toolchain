/* Software floating-point emulation.
   Convert a 128bit unsigned integer to IEEE double
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "double.h"

DFtype
__floatuntidf (UTItype i)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  DFtype a;

  FP_INIT_ROUNDMODE;
  FP_FROM_INT_D (A, i, TI_BITS, UTItype);
  FP_PACK_RAW_D (a, A);
  FP_HANDLE_EXCEPTIONS;

  return a;
}
