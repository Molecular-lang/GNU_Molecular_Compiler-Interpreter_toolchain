/* Please review: $(src-dir)/SPL-README for Licencing info. */

typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef struct { UINT64 w[2]; } UINT128;

#ifndef IN_LIBGCC2
#define _Decimal32 UINT32
#define _Decimal64 UINT64
#define _Decimal128 UINT128
#endif

void _bid_to_dpd32 (_Decimal32 *, _Decimal32 *);
void _dpd_to_bid32 (_Decimal32 *, _Decimal32 *);
void _bid_to_dpd64 (_Decimal64 *, _Decimal64 *);
void _dpd_to_bid64 (_Decimal64 *, _Decimal64 *);
void _bid_to_dpd128 (_Decimal128 *, _Decimal128 *);
void _dpd_to_bid128 (_Decimal128 *, _Decimal128 *);
