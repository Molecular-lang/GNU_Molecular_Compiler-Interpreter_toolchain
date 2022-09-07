/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

SItype
__bid_fixtdsi (_Decimal128 x) {
  union decimal128 ux;
  SItype res = 0xbaddbadd;

  ux.d = x;
  res = __bid128_to_int32_xint (ux.i);

  return (res);
}

