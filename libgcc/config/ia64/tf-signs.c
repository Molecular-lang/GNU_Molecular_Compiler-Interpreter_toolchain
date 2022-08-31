/* Please review: $(src-dir)/SPL-README for Licencing info. */

union _FP_UNION_Q
{
   __float128 flt;
   struct 
   {
      unsigned long frac0 : 64;
      unsigned long frac1 : 48;
      unsigned exp : 15;
      unsigned sign : 1;
   } bits __attribute__((packed));
};

__float128 __copysigntf3 (__float128, __float128);
__float128 __fabstf2 (__float128);
int __signbittf2 (__float128);

__float128
__copysigntf3 (__float128 a, __float128 b)
{
  union _FP_UNION_Q A, B;

  A.flt = a;
  B.flt = b;
  A.bits.sign = B.bits.sign;

  return A.flt;
}

__float128
__fabstf2 (__float128 a)
{
  union _FP_UNION_Q A;

  A.flt = a;
  A.bits.sign = 0;

  return A.flt;
}

int
__signbittf2 (__float128 a)
{
  union _FP_UNION_Q A;

  A.flt = a;

  return A.bits.sign;
}
