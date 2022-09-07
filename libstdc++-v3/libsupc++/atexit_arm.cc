// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <cxxabi.h>

#if defined(__arm__) && defined(__ARM_EABI__)

namespace __aeabiv1
{
  extern "C" int
  __aeabi_atexit (void *object, 
		  void (*destructor) (void *),
		  void *dso_handle) throw ()
  {
    return abi::__cxa_atexit(destructor, object, dso_handle);
  }
} // namespace __aeabiv1

#endif // defined(__arm__) && defined(__ARM_EABI__)
