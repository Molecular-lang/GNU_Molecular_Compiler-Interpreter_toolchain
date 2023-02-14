/* Software floating-point emulation.
   Return an IEEE half converted to IEEE extended.
*/

#define FP_NO_EXACT_UNDERFLOW
#include "soft-fp.h"
#include "half.h"
#include "extended.h"

XFtype
__extendhfxf2 (HFtype a)
{
  FP_DECL_EX;
  FP_DECL_H (A);
  FP_DECL_E (R);
  XFtype r;

  FP_INIT_EXCEPTIONS;
  FP_UNPACK_RAW_H (A, a);
#if _FP_W_TYPE_SIZE < 64
  FP_EXTEND (E, H, 4, 1, R, A);
#else
  FP_EXTEND (E, H, 2, 1, R, A);
#endif
  FP_PACK_RAW_E (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
