#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

DItype
__bid_fixtddi (_Decimal128 x) {
  DItype res = 0xbaddbaddbaddbaddull;
  union decimal128 ux;

  ux.d = x;
  res = __bid128_to_int64_xint (ux.i);

  return (res);
}


