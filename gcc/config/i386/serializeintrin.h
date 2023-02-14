#ifndef _X86GPRINTRIN_H_INCLUDED
# error "Never use <serializeintrin.h> directly; include <x86gprintrin.h> instead."
#endif

#ifndef _SERIALIZE_H_INCLUDED
#define _SERIALIZE_H_INCLUDED

#ifndef __SERIALIZE__
#pragma GCC push_options
#pragma GCC target("serialize")
#define __DISABLE_SERIALIZE__
#endif /* __SERIALIZE__ */

extern __inline void
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
_serialize (void)
{
  __builtin_ia32_serialize ();
}

#ifdef __DISABLE_SERIALIZE__
#undef __DISABLE_SERIALIZE__
#pragma GCC pop_options
#endif /* __DISABLE_SERIALIZE__ */

#endif /* _SERIALIZE_H_INCLUDED.  */
