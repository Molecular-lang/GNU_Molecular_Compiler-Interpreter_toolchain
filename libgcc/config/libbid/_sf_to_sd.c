#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal32
__bid_extendsfsd (SFtype x) {
  union decimal32 res;
  res.i = __binary32_to_bid32 (x);
  return (res.d);
}
