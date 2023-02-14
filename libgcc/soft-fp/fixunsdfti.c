/* Software floating-point emulation.
   Convert IEEE double to 128bit unsigned integer
 */

#include "soft-fp.h"
#include "double.h"

UTItype
__fixunsdfti (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  UTItype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_D (A, a);
  FP_TO_INT_D (r, A, TI_BITS, 0);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
