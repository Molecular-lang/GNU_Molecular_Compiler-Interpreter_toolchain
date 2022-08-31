/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_internal.h"

#define SIZE_MASK      0xffff8000
#define INVALID_RESULT 0x8000

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_rnint, UINT128, x,
			       bid128_to_int32_rnint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_xrnint, UINT128,
			       x, bid128_to_int32_xrnint, int,
			       SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_rninta, UINT128,
			       x, bid128_to_int32_rninta, int,
			       SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_xrninta, UINT128,
			       x, bid128_to_int32_xrninta, int,
			       SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_int, UINT128, x,
			       bid128_to_int32_int, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_xint, UINT128, x,
			       bid128_to_int32_xint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_floor, UINT128, x,
			       bid128_to_int32_floor, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_ceil, UINT128, x,
			       bid128_to_int32_ceil, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_xfloor, UINT128,
			       x, bid128_to_int32_xfloor, int,
			       SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid128_to_int16_xceil, UINT128, x,
			       bid128_to_int32_xceil, int, SIZE_MASK,
			       INVALID_RESULT)
