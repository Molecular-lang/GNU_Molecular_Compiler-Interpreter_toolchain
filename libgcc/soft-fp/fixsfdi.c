/* Software floating-point emulation.
   Convert a to 64bit signed integer
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "single.h"

DItype
__fixsfdi (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  UDItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
  FP_TO_INT_S (r, A, DI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
