/* Software floating-point emulation.
   Convert a IEEE half to 64bit signed integer
 */

#include "soft-fp.h"
#include "half.h"

DItype
__fixhfdi (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  UDItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
  FP_TO_INT_H (r, A, DI_BITS, 1);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
