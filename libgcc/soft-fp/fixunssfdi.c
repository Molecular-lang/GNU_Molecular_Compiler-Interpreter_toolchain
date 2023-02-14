/* Software floating-point emulation.
   Convert a to 64bit unsigned integer
 */

#include "soft-fp.h"
#include "single.h"

UDItype
__fixunssfdi (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  UDItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
  FP_TO_INT_S (r, A, DI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
