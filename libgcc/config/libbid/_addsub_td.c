#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h" 

_Decimal128
__bid_addtd3 (_Decimal128 x, _Decimal128 y) {
  union decimal128 ux, uy, res;

  ux.d = x;
  uy.d = y;
  res.i = __bid128_add (ux.i, uy.i);
  return (res.d);
}

_Decimal128
__bid_subtd3 (_Decimal128 x, _Decimal128 y) {
  union decimal128 ux, uy, res;

  ux.d = x;
  uy.d = y;
  res.i = __bid128_sub (ux.i, uy.i);
  return (res.d);
}
