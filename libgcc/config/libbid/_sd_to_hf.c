#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_HF_MODE || BID_HAS_HF_MODE
HFtype
__bid_truncsdhf (_Decimal32 x) {
  HFtype res;
  union decimal32 ux;

  ux.d = x;
  res = __bid32_to_binary32 (ux.i);
  return (res);
}
#endif
