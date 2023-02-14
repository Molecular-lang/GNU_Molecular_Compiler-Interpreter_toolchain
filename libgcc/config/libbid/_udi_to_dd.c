#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal64
__bid_floatunsdidd (UDItype x) {
  union decimal64 res;

  res.i = __bid64_from_uint64 (x);
  return (res.d);
}

