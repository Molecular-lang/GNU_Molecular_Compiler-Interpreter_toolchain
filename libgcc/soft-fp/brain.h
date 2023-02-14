/* Software floating-point emulation.
   Definitions for Brain Floating Point format (bfloat16).
 */

#ifndef SOFT_FP_BRAIN_H
#define SOFT_FP_BRAIN_H	1

#if _FP_W_TYPE_SIZE < 32
# error "Here's a nickel kid.  Go buy yourself a real computer."
#endif

#define _FP_FRACTBITS_B		(_FP_W_TYPE_SIZE)

#define _FP_FRACTBITS_DW_B	(_FP_W_TYPE_SIZE)

#define _FP_FRACBITS_B		8
#define _FP_FRACXBITS_B		(_FP_FRACTBITS_B - _FP_FRACBITS_B)
#define _FP_WFRACBITS_B		(_FP_WORKBITS + _FP_FRACBITS_B)
#define _FP_WFRACXBITS_B	(_FP_FRACTBITS_B - _FP_WFRACBITS_B)
#define _FP_EXPBITS_B		8
#define _FP_EXPBIAS_B		127
#define _FP_EXPMAX_B		255

#define _FP_QNANBIT_B		((_FP_W_TYPE) 1 << (_FP_FRACBITS_B-2))
#define _FP_QNANBIT_SH_B	((_FP_W_TYPE) 1 << (_FP_FRACBITS_B-2+_FP_WORKBITS))
#define _FP_IMPLBIT_B		((_FP_W_TYPE) 1 << (_FP_FRACBITS_B-1))
#define _FP_IMPLBIT_SH_B	((_FP_W_TYPE) 1 << (_FP_FRACBITS_B-1+_FP_WORKBITS))
#define _FP_OVERFLOW_B		((_FP_W_TYPE) 1 << (_FP_WFRACBITS_B))

#define _FP_WFRACBITS_DW_B	(2 * _FP_WFRACBITS_B)
#define _FP_WFRACXBITS_DW_B	(_FP_FRACTBITS_DW_B - _FP_WFRACBITS_DW_B)
#define _FP_HIGHBIT_DW_B	\
  ((_FP_W_TYPE) 1 << (_FP_WFRACBITS_DW_B - 1) % _FP_W_TYPE_SIZE)

/* The implementation of _FP_MUL_MEAT_B and _FP_DIV_MEAT_B should be
   chosen by the target machine.  */

typedef float BFtype __attribute__ ((mode (BF)));

union _FP_UNION_B
{
  BFtype flt;
  struct _FP_STRUCT_LAYOUT
  {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned sign : 1;
    unsigned exp  : _FP_EXPBITS_B;
    unsigned frac : _FP_FRACBITS_B - (_FP_IMPLBIT_B != 0);
#else
    unsigned frac : _FP_FRACBITS_B - (_FP_IMPLBIT_B != 0);
    unsigned exp  : _FP_EXPBITS_B;
    unsigned sign : 1;
#endif
  } bits;
};

#define FP_DECL_B(X)		_FP_DECL (1, X)
#define FP_UNPACK_RAW_B(X, val)	_FP_UNPACK_RAW_1 (B, X, (val))
#define FP_UNPACK_RAW_BP(X, val)	_FP_UNPACK_RAW_1_P (B, X, (val))
#define FP_PACK_RAW_B(val, X)	_FP_PACK_RAW_1 (B, (val), X)
#define FP_PACK_RAW_BP(val, X)			\
  do						\
    {						\
      if (!FP_INHIBIT_RESULTS)			\
	_FP_PACK_RAW_1_P (B, (val), X);		\
    }						\
  while (0)

#define FP_UNPACK_B(X, val)			\
  do						\
    {						\
      _FP_UNPACK_RAW_1 (B, X, (val));		\
      _FP_UNPACK_CANONICAL (B, 1, X);		\
    }						\
  while (0)

#define FP_UNPACK_BP(X, val)			\
  do						\
    {						\
      _FP_UNPACK_RAW_1_P (B, X, (val));		\
      _FP_UNPACK_CANONICAL (B, 1, X);		\
    }						\
  while (0)

#define FP_UNPACK_SEMIRAW_B(X, val)		\
  do						\
    {						\
      _FP_UNPACK_RAW_1 (B, X, (val));		\
      _FP_UNPACK_SEMIRAW (B, 1, X);		\
    }						\
  while (0)

#define FP_UNPACK_SEMIRAW_BP(X, val)		\
  do						\
    {						\
      _FP_UNPACK_RAW_1_P (B, X, (val));		\
      _FP_UNPACK_SEMIRAW (B, 1, X);		\
    }						\
  while (0)

#define FP_PACK_B(val, X)			\
  do						\
    {						\
      _FP_PACK_CANONICAL (B, 1, X);		\
      _FP_PACK_RAW_1 (B, (val), X);		\
    }						\
  while (0)

#define FP_PACK_BP(val, X)			\
  do						\
    {						\
      _FP_PACK_CANONICAL (B, 1, X);		\
      if (!FP_INHIBIT_RESULTS)			\
	_FP_PACK_RAW_1_P (B, (val), X);		\
    }						\
  while (0)

#define FP_PACK_SEMIRAW_B(val, X)		\
  do						\
    {						\
      _FP_PACK_SEMIRAW (B, 1, X);		\
      _FP_PACK_RAW_1 (B, (val), X);		\
    }						\
  while (0)

#define FP_PACK_SEMIRAW_BP(val, X)		\
  do						\
    {						\
      _FP_PACK_SEMIRAW (B, 1, X);		\
      if (!FP_INHIBIT_RESULTS)			\
	_FP_PACK_RAW_1_P (B, (val), X);		\
    }						\
  while (0)

#define FP_TO_INT_B(r, X, rsz, rsg)	_FP_TO_INT (B, 1, (r), X, (rsz), (rsg))
#define FP_TO_INT_ROUND_B(r, X, rsz, rsg)	\
  _FP_TO_INT_ROUND (B, 1, (r), X, (rsz), (rsg))
#define FP_FROM_INT_B(X, r, rs, rt)	_FP_FROM_INT (B, 1, X, (r), (rs), rt)

/* BFmode arithmetic is not implemented.  */

#define _FP_FRAC_HIGH_B(X)	_FP_FRAC_HIGH_1 (X)
#define _FP_FRAC_HIGH_RAW_B(X)	_FP_FRAC_HIGH_1 (X)
#define _FP_FRAC_HIGH_DW_B(X)	_FP_FRAC_HIGH_1 (X)

#define FP_CMP_EQ_B(r, X, Y, ex)       _FP_CMP_EQ (B, 1, (r), X, Y, (ex))

#endif /* !SOFT_FP_BRAIN_H */
