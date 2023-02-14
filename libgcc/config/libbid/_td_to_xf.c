#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#ifdef __LIBGCC_HAS_XF_MODE__
XFtype
__bid_trunctdxf (_Decimal128 x) {
  XFtype res;
  union decimal128 ux;

  ux.d = x;
  res = __bid128_to_binary80 (ux.i);
  return (res);
}
#endif
