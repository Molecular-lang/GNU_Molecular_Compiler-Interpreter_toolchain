/*
 * Please review: $(src-dir)/SPL-README for Licencing info.
 */

#ifndef _SOFT_FLOAT
#include "sfp-machine.h"

struct fenv
{
  unsigned short int __control_word;
  unsigned short int __unused1;
  unsigned short int __status_word;
  unsigned short int __unused2;
  unsigned short int __tags;
  unsigned short int __unused3;
  unsigned int __eip;
  unsigned short int __cs_selector;
  unsigned int __opcode:11;
  unsigned int __unused4:5;
  unsigned int __data_offset;
  unsigned short int __data_selector;
  unsigned short int __unused5;
} __attribute__ ((gcc_struct));

#ifdef __SSE_MATH__
# define __math_force_eval_div(x, y) \
  do { asm ("" : "+x" (x)); asm volatile ("" : : "x" (x / y)); } while (0)
#else
# define __math_force_eval_div(x, y) \
  do { asm ("" : "+t" (x)); asm volatile ("" : : "f" (x / y)); } while (0)
#endif

void
__sfp_handle_exceptions (int _fex)
{
  struct fenv temp;

  if (_fex & FP_EX_INVALID)
    {
      float f = 0.0f;
      __math_force_eval_div (f, f);
    }
  if (_fex & FP_EX_DENORM)
    {
      asm volatile ("fnstenv\t%0" : "=m" (temp));
      temp.__status_word |= FP_EX_DENORM;
      asm volatile ("fldenv\t%0" : : "m" (temp));
      asm volatile ("fwait");
    }
  if (_fex & FP_EX_DIVZERO)
    {
      float f = 1.0f, g = 0.0f;
      __math_force_eval_div (f, g);
    }
  if (_fex & FP_EX_OVERFLOW)
    {
      asm volatile ("fnstenv\t%0" : "=m" (temp));
      temp.__status_word |= FP_EX_OVERFLOW;
      asm volatile ("fldenv\t%0" : : "m" (temp));
      asm volatile ("fwait");
    }
  if (_fex & FP_EX_UNDERFLOW)
    {
      asm volatile ("fnstenv\t%0" : "=m" (temp));
      temp.__status_word |= FP_EX_UNDERFLOW;
      asm volatile ("fldenv\t%0" : : "m" (temp));
      asm volatile ("fwait");
    }
  if (_fex & FP_EX_INEXACT)
    {
      float f = 1.0f, g = 3.0f;
      __math_force_eval_div (f, g);
    }
}
#endif
