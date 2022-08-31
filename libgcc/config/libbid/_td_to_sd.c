/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"
 
_Decimal32
__bid_trunctdsd2 (_Decimal128 x) {
  union decimal128 ux;
  union decimal32 res;

  ux.d = x;
  res.i = __bid128_to_bid32 (ux.i);
  return (res.d);
}
