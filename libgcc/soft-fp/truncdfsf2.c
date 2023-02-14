/* Software floating-point emulation.
   Truncate IEEE double into IEEE single
 */

#include "soft-fp.h"
#include "single.h"
#include "double.h"

SFtype
__truncdfsf2 (DFtype a)
{
  FP_DECL_EX;
  FP_DECL_D (A);
  FP_DECL_S (R);
  SFtype r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_SEMIRAW_D (A, a);
#if _FP_W_TYPE_SIZE < _FP_FRACBITS_D
  FP_TRUNC (S, D, 1, 2, R, A);
#else
  FP_TRUNC (S, D, 1, 1, R, A);
#endif
  FP_PACK_SEMIRAW_S (r, R);
  FP_HANDLE_EXCEPTIONS;

  return r;
}
