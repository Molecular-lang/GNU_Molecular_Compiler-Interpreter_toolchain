/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal64
__bid_floatdidd (DItype x) {
  union decimal64 res;

  res.i = __bid64_from_int64 (x);
  return (res.d);
}

