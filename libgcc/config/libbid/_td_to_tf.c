/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_TF_MODE || BID_HAS_TF_MODE
TFtype
__bid_trunctdtf (_Decimal128 x) {
  union float128 res;
  union decimal128 ux;

  ux.d = x;
  res.i = __bid128_to_binary128 (ux.i);
  return (res.f);
}
#endif
