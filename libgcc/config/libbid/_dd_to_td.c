#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"
 
_Decimal128
__bid_extendddtd2 (_Decimal64 x) {
  union decimal128 res;
  union decimal64 ux;

  ux.d = x;
  res.i = __bid64_to_bid128 (ux.i);
  return (res.d);
}
