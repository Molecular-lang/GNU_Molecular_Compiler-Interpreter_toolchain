/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_internal.h"

#define SIZE_MASK      0xffff0000
#define INVALID_RESULT 0x8000

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_rnint,
				UINT64, x, bid64_to_uint32_rnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_xrnint,
				UINT64, x, bid64_to_uint32_xrnint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_rninta,
				UINT64, x, bid64_to_uint32_rninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_xrninta,
				UINT64, x, bid64_to_uint32_xrninta,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_int,
				UINT64, x, bid64_to_uint32_int,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_xint,
				UINT64, x, bid64_to_uint32_xint,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_floor,
				UINT64, x, bid64_to_uint32_floor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_ceil,
				UINT64, x, bid64_to_uint32_ceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_xfloor,
				UINT64, x, bid64_to_uint32_xfloor,
				unsigned int, SIZE_MASK, INVALID_RESULT)

BID_TO_SMALL_UINT_CVT_FUNCTION (unsigned short, bid64_to_uint16_xceil,
				UINT64, x, bid64_to_uint32_xceil,
				unsigned int, SIZE_MASK, INVALID_RESULT)
