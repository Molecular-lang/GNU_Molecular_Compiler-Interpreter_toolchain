#include "bid_internal.h"

#define SIZE_MASK      0xffffff00
#define INVALID_RESULT 0x80

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_rnint,
				UINT64, x, bid64_to_uint32_rnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_xrnint,
				UINT64, x, bid64_to_uint32_xrnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_rninta,
				UINT64, x, bid64_to_uint32_rninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_xrninta,
				UINT64, x, bid64_to_uint32_xrninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_int,
				UINT64, x, bid64_to_uint32_int,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_xint,
				UINT64, x, bid64_to_uint32_xint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_floor,
				UINT64, x, bid64_to_uint32_floor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_ceil,
				UINT64, x, bid64_to_uint32_ceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_xfloor,
				UINT64, x, bid64_to_uint32_xfloor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned char, bid64_to_uint8_xceil,
				UINT64, x, bid64_to_uint32_xceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)
