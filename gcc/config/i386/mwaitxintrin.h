/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _MWAITXINTRIN_H_INCLUDED
#define _MWAITXINTRIN_H_INCLUDED

#ifndef __MWAITX__
#pragma GCC push_options
#pragma GCC target("mwaitx")
#define __DISABLE_MWAITX__
#endif /* __MWAITX__ */

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_monitorx (void const * __P, unsigned int __E, unsigned int __H)
{
  __builtin_ia32_monitorx (__P, __E, __H);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mwaitx (unsigned int __E, unsigned int __H, unsigned int __C)
{
  __builtin_ia32_mwaitx (__E, __H, __C);
}

#ifdef __DISABLE_MWAITX__
#undef __DISABLE_MWAITX__
#pragma GCC pop_options
#endif /* __DISABLE_MWAITX__ */

#endif /* _MWAITXINTRIN_H_INCLUDED */
