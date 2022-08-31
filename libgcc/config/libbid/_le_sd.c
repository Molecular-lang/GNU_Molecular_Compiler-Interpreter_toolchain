/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

CMPtype
__bid_lesd2 (_Decimal32 x, _Decimal32 y) {
  CMPtype res;
  UINT64 x64, y64;
  union decimal32 ux, uy;
 
  ux.d = x;
  uy.d = y;
  x64 = __bid32_to_bid64 (ux.i);
  y64 = __bid32_to_bid64 (uy.i);
  res = __bid64_quiet_less_equal (x64, y64);
  if (res != 0)
    res = -1;
  else
    res = 1;
  return (res);
}
