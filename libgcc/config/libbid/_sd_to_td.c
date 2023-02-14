#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"
 
_Decimal128
__bid_extendsdtd2 (_Decimal32 x) {
  union decimal128 res;
  union decimal32 ux;

  ux.d = x;
  res.i = __bid32_to_bid128 (ux.i);
  return (res.d);
}
