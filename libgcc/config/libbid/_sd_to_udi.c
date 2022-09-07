/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

UDItype
__bid_fixunssddi (_Decimal32 x) {
  UDItype res = 0xbaddbaddbaddbaddull;
  UINT64 x64;
  union decimal32 ux;

  ux.d = x;
  x64 = __bid32_to_bid64 (ux.i);
  res = __bid64_to_uint64_xint (x64);

  if (res == 0x8000000000000000ull) res = 0; // for NaNs too
  return (res);
}

