#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal128
__bid_extenddftd (DFtype x) {
  union decimal128 res;
  res.i = __binary64_to_bid128 (x);
  return (res.d);
}
