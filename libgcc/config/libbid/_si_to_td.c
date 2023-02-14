#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal128
__bid_floatsitd (SItype x) {
  union decimal128 res;

  res.i = __bid128_from_int32 (x);
  return (res.d);
}
