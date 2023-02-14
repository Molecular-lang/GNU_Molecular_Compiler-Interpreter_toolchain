#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

SFtype
__bid_truncddsf (_Decimal64 x) {
  SFtype res;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_to_binary32 (ux.i);
  return (res);
}
