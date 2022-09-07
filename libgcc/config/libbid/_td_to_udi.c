/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

UDItype
__bid_fixunstddi (_Decimal128 x) {
  UDItype res = 0xbaddbaddbaddbaddull;
  union decimal128 ux;

  ux.d = x;

  res = __bid128_to_uint64_xint (ux.i);

  if (res == 0x8000000000000000ull) res = 0; // for NaNs too
  return (res);
}


