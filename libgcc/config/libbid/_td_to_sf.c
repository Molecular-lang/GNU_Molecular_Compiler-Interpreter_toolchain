#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

SFtype
__bid_trunctdsf (_Decimal128 x) {
  SFtype res;
  union decimal128 ux;

  ux.d = x;
  res = __bid128_to_binary32 (ux.i);
  return (res);
}
