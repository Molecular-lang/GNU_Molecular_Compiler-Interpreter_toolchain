/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _MWAITINTRIN_H_INCLUDED
#define _MWAITINTRIN_H_INCLUDED

#ifndef __MWAIT__
#pragma GCC push_options
#pragma GCC target("mwait")
#define __DISABLE_MWAIT__
#endif /* __MWAIT__ */

extern __inline void
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_monitor (void const * __P, unsigned int __E, unsigned int __H)
{
  __builtin_ia32_monitor (__P, __E, __H);
}

extern __inline void
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mwait (unsigned int __E, unsigned int __H)
{
  __builtin_ia32_mwait (__E, __H);
}

#ifdef __DISABLE_MWAIT__
#undef __DISABLE_MWAIT__
#pragma GCC pop_options
#endif /* __DISABLE_MWAIT__ */

#endif /* _MWAITINTRIN_H_INCLUDED */
