#include "sfp-machine.h"

void
__sfp_handle_exceptions (int _fex)
{
  double d;

  if (_fex & FP_EX_INVALID)
    {
      asm volatile ("frcpa.s0 %0, p1 = f0, f0" : "=f" (d) : : "p1");
    }
  if (_fex & FP_EX_DIVZERO)
    {
      asm volatile ("frcpa.s0 %0, p1 = f1, f0" : "=f" (d) : : "p1");
    }
  if (_fex & FP_EX_OVERFLOW)
    {
      d = __DBL_MAX__;
      asm volatile ("fadd.d.s0 %0 = %0, %0" : "+f" (d));
    }
  if (_fex & FP_EX_UNDERFLOW)
    {
      d = __DBL_MIN__;
      asm volatile ("fnma.d.s0 %0 = %0, %0, f0" : "+f" (d));
    }
  if (_fex & FP_EX_INEXACT)
    {
      d = __DBL_MAX__;
      asm volatile ("fsub.d.s0 %0 = %0, f1" : "+f" (d));
    }
}
