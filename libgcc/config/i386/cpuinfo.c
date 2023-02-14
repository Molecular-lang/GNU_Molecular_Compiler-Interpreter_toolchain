/* Get CPU type and Features for x86 processors. */

#include "cpuid.h"
#include "tsystem.h"
#include "auto-target.h"
#include "common/config/i386/i386-cpuinfo.h"
#include "common/config/i386/cpuinfo.h"

#ifdef HAVE_INIT_PRIORITY
#define CONSTRUCTOR_PRIORITY (101)
#else
#define CONSTRUCTOR_PRIORITY
#endif

int __cpu_indicator_init (void)
  __attribute__ ((constructor CONSTRUCTOR_PRIORITY));


struct __processor_model __cpu_model = { };
/* We want to move away from __cpu_model in libgcc_s.so.1 and the
   size of __cpu_model is part of ABI.  So, new features that don't
   fit into __cpu_model.__cpu_features[0] go into extra variables
   in libgcc.a only, preferably hidden.

   NB: Since older 386-builtins.c accesses __cpu_features2 as scalar or
   smaller array, it can only access the first few elements.  */
unsigned int __cpu_features2[SIZE_OF_CPU_FEATURES];

/* A constructor function that is sets __cpu_model and __cpu_features with
   the right values.  This needs to run only once.  This constructor is
   given the highest priority and it should run before constructors without
   the priority set.  However, it still runs after ifunc initializers and
   needs to be called explicitly there.  */

int __attribute__ ((constructor CONSTRUCTOR_PRIORITY))
__cpu_indicator_init (void)
{
  struct __processor_model2 cpu_model2;
  return cpu_indicator_init (&__cpu_model, &cpu_model2,
			     __cpu_features2);
}

#if defined SHARED && defined USE_ELF_SYMVER
__asm__ (".symver __cpu_indicator_init, __cpu_indicator_init@GCC_4.8.0");
__asm__ (".symver __cpu_model, __cpu_model@GCC_4.8.0");
#endif
