/*
 * Please review: $(src-dir)/SPL-README for Licencing info.
 */

#ifndef _SOFT_FLOAT
#define MXCSR_DAZ (1 << 6)	/* Enable denormals are zero mode */
#define MXCSR_FTZ (1 << 15)	/* Enable flush to zero mode */

#ifndef __x86_64__
/* All 64-bit targets have SSE and DAZ;
   only check them explicitly for 32-bit ones. */
#include "cpuid.h"

__attribute__ ((target("fxsr,sse")))
static void
/* The i386 ABI only requires 4-byte stack alignment, so this is necessary
   to make sure the fxsave struct gets correct alignment.
   See PR27537 and PR28621.  */
__attribute__ ((force_align_arg_pointer))
set_fast_math_sse (unsigned int edx)
{
  unsigned int mxcsr;
  
  if (edx & bit_FXSAVE)
    {
      /* Check if DAZ is available.  */
      struct
      {
	unsigned short cwd;
	unsigned short swd;
	unsigned short twd;
	unsigned short fop;
	unsigned int fip;
	unsigned int fcs;
	unsigned int foo;
	unsigned int fos;
	unsigned int mxcsr;
	unsigned int mxcsr_mask;
	unsigned int st_space[32];
	unsigned int xmm_space[32];
	unsigned int padding[56];
      } __attribute__ ((aligned (16))) fxsave;

      /* This is necessary since some implementations of FXSAVE
	 do not modify reserved areas within the image.  */
      fxsave.mxcsr_mask = 0;

      __builtin_ia32_fxsave (&fxsave);

      mxcsr = fxsave.mxcsr;

      if (fxsave.mxcsr_mask & MXCSR_DAZ)
	mxcsr |= MXCSR_DAZ;
    }
  else
    mxcsr = __builtin_ia32_stmxcsr ();

  mxcsr |= MXCSR_FTZ;
  __builtin_ia32_ldmxcsr (mxcsr);
}
#endif

static void __attribute__((constructor))
set_fast_math (void)
{
#ifndef __x86_64__
  unsigned int eax, ebx, ecx, edx;

  if (!__get_cpuid (1, &eax, &ebx, &ecx, &edx))
    return;

  if (edx & bit_SSE)
    set_fast_math_sse (edx);
#else
  unsigned int mxcsr = __builtin_ia32_stmxcsr ();
  mxcsr |= MXCSR_DAZ | MXCSR_FTZ;
  __builtin_ia32_ldmxcsr (mxcsr);
#endif
}
#endif
