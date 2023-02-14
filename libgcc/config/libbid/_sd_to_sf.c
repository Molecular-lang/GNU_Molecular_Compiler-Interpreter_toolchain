#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

SFtype
__bid_truncsdsf (_Decimal32 x) {
  SFtype res;
  union decimal32 ux;

  ux.d = x;
  res = __bid32_to_binary32 (ux.i);
  return (res);
}
