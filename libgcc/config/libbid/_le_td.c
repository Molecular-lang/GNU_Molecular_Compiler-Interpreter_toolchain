/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

CMPtype
__bid_letd2 (_Decimal128 x, _Decimal128 y) {
  CMPtype res;
  union decimal128 ux, uy;
 
  ux.d = x;
  uy.d = y;
  res = __bid128_quiet_less_equal (ux.i, uy.i);
  if (res != 0)
    res = -1;
  else
    res = 1;
  return (res);
}
