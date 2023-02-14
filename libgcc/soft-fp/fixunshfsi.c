/* Software floating-point emulation.
   Convert IEEE half to 32bit unsigned integer
*/

#include "soft-fp.h"
#include "half.h"

USItype
__fixunshfsi (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  USItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
  FP_TO_INT_H (r, A, SI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
