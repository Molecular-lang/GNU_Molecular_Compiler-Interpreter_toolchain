/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#ifdef __LIBGCC_HAS_XF_MODE__
_Decimal32
__bid_truncxfsd (XFtype x) {
  union decimal32 res;
  res.i = __binary80_to_bid32 (x);
  return (res.d);
}
#endif
