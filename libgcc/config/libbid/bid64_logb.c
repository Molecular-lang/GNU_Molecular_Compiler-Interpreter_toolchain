/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_internal.h"

#define MAX_FORMAT_DIGITS     16
#define DECIMAL_EXPONENT_BIAS 398

#if DECIMAL_CALL_BY_REFERENCE

void
bid64_logb (int * pres, UINT64 * px
	    _EXC_FLAGS_PARAM _EXC_MASKS_PARAM _EXC_INFO_PARAM) {
  UINT64 x;
#else

int
bid64_logb (UINT64 x _EXC_FLAGS_PARAM _EXC_MASKS_PARAM _EXC_INFO_PARAM) {
#endif
  UINT64 sign_x, coefficient_x;
  int_double dx;
  int exponent_x, bin_expon_cx, digits;

#if DECIMAL_CALL_BY_REFERENCE
  x = *px;
#endif
  // unpack arguments, check for NaN or Infinity
  if (!unpack_BID64 (&sign_x, &exponent_x, &coefficient_x, x)) {
    // x is Inf. or NaN
#ifdef SET_STATUS_FLAGS
      __set_status_flags (pfpsf, INVALID_EXCEPTION);
#endif
      BID_RETURN (0x80000000);
  }
  // find number of digits in coefficient
  if (coefficient_x >= 1000000000000000ull) {
    digits = 16;
  } else {
    dx.d = (double)coefficient_x;   // exact conversion;
    bin_expon_cx = (int)(dx.i >> 52) - 1023;
    digits = estimate_decimal_digits[bin_expon_cx];
    if (coefficient_x >= power10_table_128[digits].w[0])
      digits++;
  }
  exponent_x = exponent_x - DECIMAL_EXPONENT_BIAS + digits - 1;

  BID_RETURN (exponent_x);
}
