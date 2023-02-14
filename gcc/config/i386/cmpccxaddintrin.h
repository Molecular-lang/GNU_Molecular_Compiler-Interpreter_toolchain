#ifndef _X86GPRINTRIN_H_INCLUDED
#error "Never use <cmpccxaddintrin.h> directly; include <x86gprintrin.h> instead."
#endif

#ifndef _CMPCCXADDINTRIN_H_INCLUDED
#define _CMPCCXADDINTRIN_H_INCLUDED

#ifdef __x86_64__

#ifndef __CMPCCXADD__
#pragma GCC push_options
#pragma GCC target("cmpccxadd")
#define __DISABLE_CMPCCXADD__
#endif /* __CMPCCXADD__ */

typedef enum {
    _CMPCCX_O,   /* Overflow.  */
    _CMPCCX_NO,  /* No overflow.  */
    _CMPCCX_B,   /* Below.  */
    _CMPCCX_NB,  /* Not below.  */
    _CMPCCX_Z,   /* Zero.  */
    _CMPCCX_NZ,  /* Not zero.  */
    _CMPCCX_BE,  /* Below or equal.  */
    _CMPCCX_NBE, /* Neither below nor equal.  */
    _CMPCCX_S,   /* Sign.  */
    _CMPCCX_NS,  /* No sign.  */
    _CMPCCX_P,   /* Parity.  */
    _CMPCCX_NP,  /* No parity.  */
    _CMPCCX_L,   /* Less.  */
    _CMPCCX_NL,  /* Not less.  */
    _CMPCCX_LE,  /* Less or equal.  */
    _CMPCCX_NLE, /* Neither less nor equal.  */
} _CMPCCX_ENUM;

#ifdef __OPTIMIZE__
extern __inline int
__attribute__ ((__gnu_inline__, __always_inline__, __artificial__))
_cmpccxadd_epi32 (int *__A, int __B, int __C, const _CMPCCX_ENUM __D)
{
  return __builtin_ia32_cmpccxadd (__A, __B, __C, __D);
}

extern __inline long long
__attribute__ ((__gnu_inline__, __always_inline__, __artificial__))
_cmpccxadd_epi64 (long long *__A, long long __B, long long __C,
		   const _CMPCCX_ENUM __D)
{
  return __builtin_ia32_cmpccxadd64 (__A, __B, __C, __D);
}
#else
#define _cmpccxadd_epi32(A,B,C,D) \
  __builtin_ia32_cmpccxadd ((int *) (A), (int) (B), (int) (C), \
			    (_CMPCCX_ENUM) (D))
#define _cmpccxadd_epi64(A,B,C,D) \
  __builtin_ia32_cmpccxadd64 ((long long *) (A), (long long) (B), \
			      (long long) (C), (_CMPCCX_ENUM) (D))
#endif

#ifdef __DISABLE_CMPCCXADD__
#undef __DISABLE_CMPCCXADD__
#pragma GCC pop_options
#endif /* __DISABLE_CMPCCXADD__ */

#endif

#endif /* _CMPCCXADDINTRIN_H_INCLUDED */
