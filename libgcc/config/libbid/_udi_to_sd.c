/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

_Decimal32
__bid_floatunsdisd (UDItype x) {
  union decimal32 res;
  UINT64 res64;

  res64 = __bid64_from_uint64 (x);
  res.i = __bid64_to_bid32 (res64);
  return (res.d);
}
