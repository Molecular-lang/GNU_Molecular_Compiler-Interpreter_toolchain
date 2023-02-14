#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

int
isinfd64 (_Decimal64 x) {
  int res;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_isInf (ux.i);
  return (res);
}

