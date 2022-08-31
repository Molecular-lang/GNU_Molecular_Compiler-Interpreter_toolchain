/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"
 
_Decimal64
__bid_extendsddd2 (_Decimal32 x) {
  union decimal64 res;
  union decimal32 ux;

  ux.d = x;
  res.i = __bid32_to_bid64 (ux.i);
  return (res.d);
}
