/* Software floating-point emulation.
   Convert a to 64bit signed integer
 */

#include "soft-fp.h"
#include "double.h"

DItype
__fixdfdi (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  UDItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_TO_INT_D (r, A, DI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
