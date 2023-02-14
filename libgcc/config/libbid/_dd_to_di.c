#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

DItype
__bid_fixdddi (_Decimal64 x) {
  DItype res = 0xbaddbaddbaddbaddull;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_to_int64_xint (ux.i);

  return (res);
}


