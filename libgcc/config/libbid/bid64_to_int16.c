#include "bid_internal.h"

#define SIZE_MASK      0xffff8000
#define INVALID_RESULT 0x8000

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_rnint, UINT64, x,
			       bid64_to_int32_rnint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_xrnint, UINT64, x,
			       bid64_to_int32_xrnint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_rninta, UINT64, x,
			       bid64_to_int32_rninta, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_xrninta, UINT64, x,
			       bid64_to_int32_xrninta, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_int, UINT64, x,
			       bid64_to_int32_int, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_xint, UINT64, x,
			       bid64_to_int32_xint, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_floor, UINT64, x,
			       bid64_to_int32_floor, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_ceil, UINT64, x,
			       bid64_to_int32_ceil, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_xfloor, UINT64, x,
			       bid64_to_int32_xfloor, int, SIZE_MASK,
			       INVALID_RESULT)

BID_TO_SMALL_INT_CVT_FUNCTION (short, bid64_to_int16_xceil, UINT64, x,
			       bid64_to_int32_xceil, int, SIZE_MASK,
			       INVALID_RESULT)
