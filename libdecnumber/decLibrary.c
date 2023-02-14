/* Temporary library support for decimal floating point. */

#include "dconfig.h"
#include "decContext.h"
#include "decimal128.h"
#include "decimal64.h"
#include "decimal32.h"

void __host_to_ieee_32 (_Decimal32, decimal32 *);
void __host_to_ieee_64 (_Decimal64, decimal64 *);
void __host_to_ieee_128 (_Decimal128, decimal128 *);

extern int isinfd32 (_Decimal32);
extern int isinfd64 (_Decimal64);
extern int isinfd128 (_Decimal128);
uint32_t __dec_byte_swap (uint32_t);

int
isinfd32 (_Decimal32 arg)
{
  decNumber dn;
  decimal32 d32;

  __host_to_ieee_32 (arg, &d32);
  decimal32ToNumber (&d32, &dn);
  return (decNumberIsInfinite (&dn));
}

int
isinfd64 (_Decimal64 arg)
{
  decNumber dn;
  decimal64 d64;

  __host_to_ieee_64 (arg, &d64);
  decimal64ToNumber (&d64, &dn);
  return (decNumberIsInfinite (&dn));
}

int
isinfd128 (_Decimal128 arg)
{
  decNumber dn;
  decimal128 d128;

  __host_to_ieee_128 (arg, &d128);
  decimal128ToNumber (&d128, &dn);
  return (decNumberIsInfinite (&dn));
}
