/* Software floating-point emulation.
   Return a converted to IEEE double
 */

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "single.h"
#include "double.h"

DFtype
__extendsfdf2 (SFtype a)
{
  FP_DECL_EX;
  FP_DECL_S (A);
  FP_DECL_D (R);
  DFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_S (A, a);
#if _FP_W_TYPE_SIZE < _FP_FRACBITS_D
  FP_EXTEND (D, S, 2, 1, R, A);
#else
  FP_EXTEND (D, S, 1, 1, R, A);
#endif
  FP_PACK_RAW_D (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
