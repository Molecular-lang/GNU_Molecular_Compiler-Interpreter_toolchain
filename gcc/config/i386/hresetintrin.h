/* Please review: $(src-dir)/SPL-README for Licencing info. */

#if !defined _X86GPRINTRIN_H_INCLUDED
# error "Never use <hresetintrin.h> directly; include <x86gprintrin.h> instead."
#endif

#ifndef _HRESETINTRIN_H_INCLUDED
#define _HRESETINTRIN_H_INCLUDED

#ifndef __HRESET__
#pragma GCC push_options
#pragma GCC target ("hreset")
#define __DISABLE_HRESET__
#endif /* __HRESET__ */

extern __inline void
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_hreset (unsigned int __EAX)
{
  __builtin_ia32_hreset (__EAX);
}

#ifdef __DISABLE_HRESET__
#undef __DISABLE_HRESET__
#pragma GCC pop_options
#endif /* __DISABLE_HRESET__ */
#endif /* _HRESETINTRIN_H_INCLUDED.  */
