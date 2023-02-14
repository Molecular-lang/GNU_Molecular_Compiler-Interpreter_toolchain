#include "bid_internal.h"

#define SIZE_MASK      0xffffff80
#define INVALID_RESULT 0x80

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_rnint, UINT128, x,
			       bid128_to_int32_rnint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_xrnint, UINT128, x,
			       bid128_to_int32_xrnint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_rninta, UINT128, x,
			       bid128_to_int32_rninta, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_xrninta, UINT128, x,
			       bid128_to_int32_xrninta, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_int, UINT128, x,
			       bid128_to_int32_int, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_xint, UINT128, x,
			       bid128_to_int32_xint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_floor, UINT128, x,
			       bid128_to_int32_floor, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_ceil, UINT128, x,
			       bid128_to_int32_ceil, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_xfloor, UINT128, x,
			       bid128_to_int32_xfloor, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (char, bid128_to_int8_xceil, UINT128, x,
			       bid128_to_int32_xceil, int, SIZE_MASK,
			       INVALID_RESULT)
