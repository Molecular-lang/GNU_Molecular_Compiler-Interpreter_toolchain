/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

int
isinfd32 (_Decimal32 x) {
  int res;
  UINT64 x64;
  union decimal32 ux;

  ux.d = x;
  x64 = __bid32_to_bid64 (ux.i);
  res = __bid64_isInf (x64);
  return (res);
}

