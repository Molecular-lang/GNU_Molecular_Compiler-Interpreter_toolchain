/* Software floating-point emulation.
   Convert a to 64bit unsigned integer
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "quad.h"

UDItype
__fixunstfdi (TFtype a)
{
  FP_DECL_EX;
  FP_DECL_Q (A);
  UDItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_Q (A, a);
  FP_TO_INT_Q (r, A, DI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
