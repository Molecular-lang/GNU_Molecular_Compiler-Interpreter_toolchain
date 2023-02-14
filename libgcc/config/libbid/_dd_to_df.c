#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

DFtype
__bid_truncdddf (_Decimal64 x) {
  DFtype res;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_to_binary64 (ux.i);
  return (res);
}
