#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

USItype
__bid_fixunssdsi (_Decimal32 x) {
  USItype res = 0xbaddbadd;
  UINT64 x64;
  union decimal32 ux;

  ux.d = x;
  x64 = __bid32_to_bid64 (ux.i);
  res = __bid64_to_uint32_xint (x64);

  if (res == 0x80000000) res = 0; // for NaNs too
  return (res);
}

