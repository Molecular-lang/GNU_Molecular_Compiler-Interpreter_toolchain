#include "bid_internal.h"

#define SIZE_MASK      0xffff0000
#define INVALID_RESULT 0x8000

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_rnint,
				UINT128, x, bid128_to_uint32_rnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_xrnint,
				UINT128, x, bid128_to_uint32_xrnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_rninta,
				UINT128, x, bid128_to_uint32_rninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short,
				bid128_to_uint16_xrninta, UINT128, x,
				bid128_to_uint32_xrninta, unsigned int,
				SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_int,
				UINT128, x, bid128_to_uint32_int,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_xint,
				UINT128, x, bid128_to_uint32_xint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_floor,
				UINT128, x, bid128_to_uint32_floor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_ceil,
				UINT128, x, bid128_to_uint32_ceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_xfloor,
				UINT128, x, bid128_to_uint32_xfloor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid128_to_uint16_xceil,
				UINT128, x, bid128_to_uint32_xceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)
