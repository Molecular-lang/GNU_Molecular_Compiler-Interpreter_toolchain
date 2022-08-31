/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

int
isinfd128 (_Decimal128 x) {
  int res;
  union decimal128 ux;

  ux.d = x;
  res = __bid128_isInf (ux.i);
  return (res);
}

