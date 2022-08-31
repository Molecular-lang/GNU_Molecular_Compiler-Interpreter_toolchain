/* This is a software decimal floating point library.
  Please review: $(src-dir)/SPL-README for Licencing info. */

#include <string.h>

#include "dconfig.h"
#include "bid-dpd.h"
#include "decimal128.h"

void __host_to_ieee_128 (_Decimal128 in, decimal128 *out);
void __ieee_to_host_128 (decimal128 in, _Decimal128 *out);

/* The code for converting 128-bit values between DPD and BID presumes
   that the 64-bit halves of the 128-bit value are in little-endian
   order, so they need swapping on big-endian hosts.  */

void
__host_to_ieee_128 (_Decimal128 in, decimal128 *out)
{
#if WORDS_BIGENDIAN
  memcpy ((char *) out, (char *) &in + 8, 8);
  memcpy ((char *) out + 8, (char *) &in, 8);
#else
  memcpy ((char *) out, (char *) &in, 16);
#endif
}

void
__ieee_to_host_128 (decimal128 in, _Decimal128 *out)
{
#if WORDS_BIGENDIAN
  memcpy ((char *) out, (char *) &in + 8, 8);
  memcpy ((char *) out + 8, (char *) &in, 8);
#else
  memcpy ((char *) out, (char *) &in, 16);
#endif
}
