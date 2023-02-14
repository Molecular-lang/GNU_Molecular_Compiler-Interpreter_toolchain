#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

CMPtype
__bid_nedd2 (_Decimal64 x, _Decimal64 y) {
  CMPtype res;
  union decimal64 ux, uy;
 
  ux.d = x;
  uy.d = y;
  res = __bid64_quiet_not_equal (ux.i, uy.i);
  return (res);
}
