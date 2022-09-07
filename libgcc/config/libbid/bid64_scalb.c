/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_internal.h"

#define MAX_FORMAT_DIGITS     16
#define DECIMAL_EXPONENT_BIAS 398
#define MAX_DECIMAL_EXPONENT  767

#if DECIMAL_CALL_BY_REFERENCE

void
bid64_scalb (UINT64 * pres, UINT64 * px,
	     int *pn _RND_MODE_PARAM _EXC_FLAGS_PARAM _EXC_MASKS_PARAM
	     _EXC_INFO_PARAM) {
  UINT64 x;
  int n;
#else

UINT64
bid64_scalb (UINT64 x,
	     int n _RND_MODE_PARAM _EXC_FLAGS_PARAM _EXC_MASKS_PARAM
	     _EXC_INFO_PARAM) {
#endif
  UINT64 sign_x, coefficient_x, res;
  SINT64 exp64;
  int exponent_x, rmode;

#if DECIMAL_CALL_BY_REFERENCE
#if !DECIMAL_GLOBAL_ROUNDING
  _IDEC_round rnd_mode = *prnd_mode;
#endif
  x = *px;
  n = *pn;
#endif

  // unpack arguments, check for NaN or Infinity
  if (!unpack_BID64 (&sign_x, &exponent_x, &coefficient_x, x)) {
    // x is Inf. or NaN or 0
#ifdef SET_STATUS_FLAGS
    if ((x & SNAN_MASK64) == SNAN_MASK64)	// y is sNaN
      __set_status_flags (pfpsf, INVALID_EXCEPTION);
#endif
    if (coefficient_x)
      res = coefficient_x & QUIET_MASK64;
	else {
       exp64 = (SINT64) exponent_x + (SINT64) n;
	   if(exp64<0) exp64=0;
	   if(exp64>MAX_DECIMAL_EXPONENT) exp64=MAX_DECIMAL_EXPONENT;
       exponent_x = exp64;
      res = very_fast_get_BID64 (sign_x, exponent_x, coefficient_x);	// 0
	}
    BID_RETURN (res);
  }

  exp64 = (SINT64) exponent_x + (SINT64) n;
  exponent_x = exp64;

  if ((UINT32) exponent_x <= MAX_DECIMAL_EXPONENT) {
    res = very_fast_get_BID64 (sign_x, exponent_x, coefficient_x);
    BID_RETURN (res);
  }
  // check for overflow
  if (exp64 > MAX_DECIMAL_EXPONENT) {
    // try to normalize coefficient
    while ((coefficient_x < 1000000000000000ull)
	   && (exp64 > MAX_DECIMAL_EXPONENT)) {
      // coefficient_x < 10^15, scale by 10
      coefficient_x = (coefficient_x << 1) + (coefficient_x << 3);
      exponent_x--;
      exp64--;
    }
    if (exp64 <= MAX_DECIMAL_EXPONENT) {
      res = very_fast_get_BID64 (sign_x, exponent_x, coefficient_x);
      BID_RETURN (res);
    } else
      exponent_x = 0x7fffffff;	// overflow
  }
  // exponent < 0
  // the BID pack routine will round the coefficient
  rmode = rnd_mode;
  res = get_BID64 (sign_x, exponent_x, coefficient_x, rmode, pfpsf);
  BID_RETURN (res);

}
