/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_internal.h"

#define SIZE_MASK      0xffffff00
#define INVALID_RESULT 0x80

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_rnint,
				UINT128, x, bid128_to_uint32_rnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_xrnint,
				UINT128, x, bid128_to_uint32_xrnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_rninta,
				UINT128, x, bid128_to_uint32_rninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_xrninta,
				UINT128, x, bid128_to_uint32_xrninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_int,
				UINT128, x, bid128_to_uint32_int,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_xint,
				UINT128, x, bid128_to_uint32_xint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_floor,
				UINT128, x, bid128_to_uint32_floor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_ceil,
				UINT128, x, bid128_to_uint32_ceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_xfloor,
				UINT128, x, bid128_to_uint32_xfloor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid128_to_uint8_xceil,
				UINT128, x, bid128_to_uint32_xceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)
