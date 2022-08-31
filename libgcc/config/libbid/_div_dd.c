/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal64
__bid_divdd3 (_Decimal64 x, _Decimal64 y) {
  union decimal64 ux, uy, res;

  ux.d = x;
  uy.d = y;
  res.i = __bid64_div (ux.i, uy.i);
  return (res.d);
}
