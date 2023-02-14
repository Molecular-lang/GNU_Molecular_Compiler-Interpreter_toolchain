#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

CMPtype
__bid_gttd2 (_Decimal128 x, _Decimal128 y) {
  CMPtype res;
  union decimal128 ux, uy;
 
  ux.d = x;
  uy.d = y;
  res = __bid128_quiet_greater (ux.i, uy.i);
  return (res);
}
