/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

DFtype
__bid_extendsddf (_Decimal32 x) {
  DFtype res;
  union decimal32 ux;

  ux.d = x;
  res = __bid32_to_binary64 (ux.i);
  return (res);
}
