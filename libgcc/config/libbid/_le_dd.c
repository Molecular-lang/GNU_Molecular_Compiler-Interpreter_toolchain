#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

CMPtype
__bid_ledd2 (_Decimal64 x, _Decimal64 y) {
  CMPtype res;
  union decimal64 ux, uy;
 
  ux.d = x;
  uy.d = y;
  res = __bid64_quiet_less_equal (ux.i, uy.i);
  if (res != 0)
    res = -1;
  else
    res = 1;
  return (res);
}
