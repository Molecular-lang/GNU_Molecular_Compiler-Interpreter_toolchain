/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#if LIBGCC2_HAS_HF_MODE || BID_HAS_HF_MODE
_Decimal64
__bid_extendhfdd (HFtype x) {
  union decimal64 res;
  SFtype xsf = x;
  res.i = __binary32_to_bid64 (xsf);
  return (res.d);
}
#endif
