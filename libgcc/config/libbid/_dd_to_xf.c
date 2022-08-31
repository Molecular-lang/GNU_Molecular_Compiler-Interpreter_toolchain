/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_conf.h"
#include "bid_functions.h"
#include "bid_gcc_intrinsics.h"

#ifdef __LIBGCC_HAS_XF_MODE__
XFtype
__bid_extendddxf (_Decimal64 x) {
  XFtype res;
  union decimal64 ux;

  ux.d = x;
  res = __bid64_to_binary80 (ux.i);
  return (res);
}
#endif
