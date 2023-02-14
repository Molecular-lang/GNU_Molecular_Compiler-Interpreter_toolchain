#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

DItype
__bid_fixsddi (_Decimal32 x) {
  DItype res = 0xbaddbaddbaddbaddull;
  UINT64 x64;
  union decimal32 ux;

  ux.d = x;
  x64 = __bid32_to_bid64 (ux.i);
  res = __bid64_to_int64_xint (x64);

  return (res);
}


