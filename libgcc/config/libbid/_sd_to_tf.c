/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_TF_MODE || BID_HAS_TF_MODE
TFtype
__bid_extendsdtf (_Decimal32 x) {
  union float128 res;
  union decimal32 ux;

  ux.d = x;
  res.i = __bid32_to_binary128 (ux.i);
  return (res.f);
}
#endif
