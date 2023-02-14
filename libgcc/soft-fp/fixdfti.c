/* Software floating-point emulation.
   Convert IEEE double to 128bit signed integer
 */

#include "soft-fp.h"
#include "double.h"

TItype
__fixdfti (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  UTItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_TO_INT_D (r, A, TI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
