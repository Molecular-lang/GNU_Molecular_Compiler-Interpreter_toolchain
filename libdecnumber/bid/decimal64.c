#define decimal64FromString __dpd64FromString
#define decimal64ToString __dpd64ToString
#define decimal64ToEngString __dpd64ToEngString
#define decimal64FromNumber __dpd64FromNumber
#define decimal64ToNumber __dpd64ToNumber

#include "dpd/decimal64.c"

#undef decimal64FromString
#undef decimal64ToString
#undef decimal64ToEngString
#undef decimal64FromNumber
#undef decimal64ToNumber

#include "bid-dpd.h"

#ifdef IN_LIBGCC2
#define decimal64FromString __decimal64FromString
#define decimal64ToString __decimal64ToString
#define decimal64ToEngString __decimal64ToEngString
#define decimal64FromNumber __decimal64FromNumber
#define decimal64ToNumber __decimal64ToNumber
#endif

decimal64 *decimal64FromString (decimal64 *, const char *, decContext *);
char *decimal64ToString (const decimal64 *, char *);
char *decimal64ToEngString (const decimal64 *, char *);
decimal64 *decimal64FromNumber (decimal64 *, const decNumber *, decContext *);
decNumber *decimal64ToNumber (const decimal64 *, decNumber *);

void __host_to_ieee_64 (_Decimal64 in, decimal64 *out);
void __ieee_to_host_64 (decimal64 in, _Decimal64 *out);

decimal64 *
decimal64FromNumber (decimal64 *d64, const decNumber *dn,
		      decContext *set)
{
  /* decimal64 and _Decimal64 are different types.  */
  union
    {
      _Decimal64 _Dec;
      decimal64 dec;
    } u;

  __dpd64FromNumber (d64, dn, set);

  /* __dpd64FromNumber returns in big endian. But _dpd_to_bid64 takes
     host endian. */
  __ieee_to_host_64 (*d64, &u._Dec);

  /* Convert DPD to BID.  */
  _dpd_to_bid64 (&u._Dec, &u._Dec);

  /* dfp.c is in bid endian. */
  __host_to_ieee_64 (u._Dec, &u.dec);

  /* d64 is returned as a pointer to _Decimal64 here.  */
  *d64 = u.dec;

  return d64;
}

decNumber *
decimal64ToNumber (const decimal64 *bid64, decNumber *dn)
{
  /* decimal64 and _Decimal64 are different types.  */
  union
    {
      _Decimal64 _Dec;
      decimal64 dec;
    } u;

  /* bid64 is a pointer to _Decimal64 in bid endian. But _bid_to_dpd64
     takes host endian.  */
  __ieee_to_host_64 (*bid64, &u._Dec);

  /* Convert BID to DPD.  */
  _bid_to_dpd64 (&u._Dec, &u._Dec);

  /* __dpd64ToNumber is in bid endian.  */
  __host_to_ieee_64 (u._Dec, &u.dec);

  return __dpd64ToNumber (&u.dec, dn);
}

char *
decimal64ToString (const decimal64 *d64, char *string)
{
  decNumber dn;			/* work */
  decimal64ToNumber (d64, &dn);
  decNumberToString (&dn, string);
  return string;
}

char *
decimal64ToEngString (const decimal64 *d64, char *string)
{
  decNumber dn;			/* work */
  decimal64ToNumber (d64, &dn);
  decNumberToEngString (&dn, string);
  return string;
}

decimal64 *
decimal64FromString (decimal64 *result, const char *string,
		      decContext *set)
{
  decContext dc;		/* work */
  decNumber dn;			/* .. */

  decContextDefault (&dc, DEC_INIT_DECIMAL64);	/* no traps, please */
  dc.round = set->round;	/* use supplied rounding */

  decNumberFromString (&dn, string, &dc);	/* will round if needed */
  decimal64FromNumber (result, &dn, &dc);
  if (dc.status != 0)
    {				/* something happened */
      decContextSetStatus (set, dc.status);	/* .. pass it on */
    }
  return result;
}
