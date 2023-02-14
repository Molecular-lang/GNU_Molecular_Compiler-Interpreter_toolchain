#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_HF_MODE || BID_HAS_HF_MODE
_Decimal128
__bid_extendhftd (HFtype x) {
  union decimal128 res;
  SFtype xsf = x;
  res.i = __binary32_to_bid128 (xsf);
  return (res.d);
}
#endif
