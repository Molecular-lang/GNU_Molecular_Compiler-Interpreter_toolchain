#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_TF_MODE || BID_HAS_TF_MODE
TFtype
__bid_extendddtf (_Decimal64 x) {
  union float128 res;
  union decimal64 ux;

  ux.d = x;
  res.i = __bid64_to_binary128 (ux.i);
  return (res.f);
}
#endif
