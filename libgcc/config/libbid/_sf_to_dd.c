#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal64
__bid_extendsfdd (SFtype x) {
  union decimal64 res;
  res.i = __binary32_to_bid64 (x);
  return (res.d);
}
