/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal128
__bid_floatunssitd (USItype x) {
  union decimal128 res;

  res.i = __bid128_from_uint32 (x);
  return (res.d);
}

