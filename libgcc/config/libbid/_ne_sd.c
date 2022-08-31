/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

CMPtype
__bid_nesd2 (_Decimal32 x, _Decimal32 y) {
  CMPtype res;
  UINT64 x64, y64;
  union decimal32 ux, uy;
 
  ux.d = x;
  uy.d = y;
  x64 = __bid32_to_bid64 (ux.i);
  y64 = __bid32_to_bid64 (uy.i);
  res = __bid64_quiet_not_equal (x64, y64);
  return (res);
}
