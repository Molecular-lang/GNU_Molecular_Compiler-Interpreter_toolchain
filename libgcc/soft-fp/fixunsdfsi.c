/* Software floating-point emulation.
   Convert a to 32bit unsigned integer
 */

#include "soft-fp.h"
#include "double.h"

USItype
__fixunsdfsi (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  USItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_TO_INT_D (r, A, SI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
