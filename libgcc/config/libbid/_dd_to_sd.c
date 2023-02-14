#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"
 
_Decimal32
__bid_truncddsd2 (_Decimal64 x) {
  union decimal32 res;
  union decimal64 ux;

  ux.d = x;
  res.i = __bid64_to_bid32 (ux.i);
  return (res.d);
}
