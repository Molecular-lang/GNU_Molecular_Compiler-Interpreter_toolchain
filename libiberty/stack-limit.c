/* Increase stack size limit if possible.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/*

@deftypefn Extension void stack_limit_increase (unsigned long @var{pref})

Attempt to increase stack size limit to @var{pref} bytes if possible.

@end deftypefn

*/

#include "config.h"
#include "ansidecl.h"

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

void
stack_limit_increase (unsigned long pref ATTRIBUTE_UNUSED)
{
#if defined(HAVE_SETRLIMIT) && defined(HAVE_GETRLIMIT) \
    && defined(RLIMIT_STACK) && defined(RLIM_INFINITY)
  struct rlimit rlim;
  if (getrlimit (RLIMIT_STACK, &rlim) == 0
      && rlim.rlim_cur != RLIM_INFINITY
      && rlim.rlim_cur < pref
      && (rlim.rlim_max == RLIM_INFINITY || rlim.rlim_cur < rlim.rlim_max))
    {
      rlim.rlim_cur = pref;
      if (rlim.rlim_max != RLIM_INFINITY && rlim.rlim_cur > rlim.rlim_max)
	rlim.rlim_cur = rlim.rlim_max;
      setrlimit (RLIMIT_STACK, &rlim);
    }
#endif
}
