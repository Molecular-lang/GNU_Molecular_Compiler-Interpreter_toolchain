/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _X86INTRIN_H_INCLUDED
#define _X86INTRIN_H_INCLUDED

#include <x86gprintrin.h>

#ifndef __iamcu__

/* For including AVX instructions */
#include <immintrin.h>

#include <mm3dnow.h>

#include <fma4intrin.h>

#include <xopintrin.h>

#endif /* __iamcu__ */

#endif /* _X86INTRIN_H_INCLUDED */
