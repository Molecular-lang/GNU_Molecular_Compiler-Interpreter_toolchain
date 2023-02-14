#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal64
__bid_extenddfdd (DFtype x) {
  union decimal64 res;
  res.i = __binary64_to_bid64 (x);
  return (res.d);
}
