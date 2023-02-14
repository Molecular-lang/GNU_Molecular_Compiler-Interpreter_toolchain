#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_TF_MODE || BID_HAS_TF_MODE
_Decimal32
__bid_trunctfsd (TFtype x) {
  union decimal32 res;
  union float128 ux;

  ux.f = x;
  res.i = __binary128_to_bid32 (ux.i);
  return (res.d);
}
#endif
