/* Software floating-point emulation.
   Return an IEEE half converted to IEEE double
 */

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "half.h"
#include "double.h"

DFtype
__extendhfdf2 (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_D (R);
  DFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
#if _FP_W_TYPE_SIZE < _FP_FRACBITS_D
  FP_EXTEND (D, H, 2, 1, R, A);
#else
  FP_EXTEND (D, H, 1, 1, R, A);
#endif
  FP_PACK_RAW_D (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
