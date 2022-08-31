/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#ifdef __LIBGCC_HAS_XF_MODE__
_Decimal128
__bid_extendxftd (XFtype x) {
  union decimal128 res;
  res.i = __binary80_to_bid128 (x);
  return (res.d);
}
#endif
