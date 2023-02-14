#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal128
__bid_extendsftd (SFtype x) {
  union decimal128 res;
  res.i = __binary32_to_bid128 (x);
  return (res.d);
}
