/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

SItype
__bid_fixddsi (_Decimal64 x) {
  SItype res = 0xbaddbadd;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_to_int32_xint (ux.i);

  return (res);
}


