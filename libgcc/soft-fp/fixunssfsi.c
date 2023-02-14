/* Software floating-point emulation.
   Convert a to 32bit unsigned integer
 */

#include "soft-fp.h"
#include "single.h"

USItype
__fixunssfsi (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  USItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
  FP_TO_INT_S (r, A, SI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
