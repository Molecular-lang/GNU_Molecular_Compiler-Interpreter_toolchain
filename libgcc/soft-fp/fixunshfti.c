/* Software floating-point emulation.
   Convert IEEE half to 128bit unsigned integer
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "soft-fp.h"
#include "half.h"

UTItype
__fixunshfti (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  UTItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
  FP_TO_INT_H (r, A, TI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
