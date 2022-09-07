/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#ifdef __LIBGCC_HAS_XF_MODE__
XFtype
__bid_extendsdxf (_Decimal32 x) {
  XFtype res;
  union decimal32 ux;

  ux.d = x;
  res = __bid32_to_binary80 (ux.i);
  return (res);
}
#endif
