/* This is a software decimal floating point library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This implements IEEE 754R decimal floating point arithmetic, but
   does not provide a mechanism for setting the rounding mode, or for
   generating or handling exceptions.  Conversions between decimal
   floating point types and other types depend on C library functions.

   Contributed by Ben Elliston  <bje@au.ibm.com>.  */

/* The intended way to use this file is to make two copies, add `#define '
   to one copy, then compile both copies and add them to libgcc.a.  */

#include <string.h>
#include "bid-dpd.h"
#include "decimal64.h"

void __host_to_ieee_64 (_Decimal64 in, decimal64 *out);
void __ieee_to_host_64 (decimal64 in, _Decimal64 *out);

void
__host_to_ieee_64 (_Decimal64 in, decimal64 *out)
{
  memcpy ((char *) out, (char *) &in, 8);
}

void
__ieee_to_host_64 (decimal64 in, _Decimal64 *out)
{
  memcpy ((char *) out, (char *) &in, 8);
}
