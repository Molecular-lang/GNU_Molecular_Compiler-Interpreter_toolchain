/* This is a software decimal floating point library. */

/* This implements IEEE 754R decimal floating point arithmetic, but
   does not provide a mechanism for setting the rounding mode, or for
   generating or handling exceptions.  Conversions between decimal
   floating point types and other types depend on C library functions.
 */

/* The intended way to use this file is to make two copies, add `#define '
   to one copy, then compile both copies and add them to libgcc.a.  */

#include <string.h>
#include "bid-dpd.h"
#include "decimal32.h"

void __host_to_ieee_32 (_Decimal32 in, decimal32 *out);
void __ieee_to_host_32 (decimal32 in, _Decimal32 *out);

void
__host_to_ieee_32 (_Decimal32 in, decimal32 *out)
{
  memcpy ((char *) out, (char *) &in, 4);
}

void
__ieee_to_host_32 (decimal32 in, _Decimal32 *out)
{
  memcpy ((char *) out, (char *) &in, 4);
}
