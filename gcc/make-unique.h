/* Minimal implementation of make_unique for C++11 compatibility. */

#ifndef GCC_MAKE_UNIQUE
#define GCC_MAKE_UNIQUE

/* This header uses std::unique_ptr, but <memory> can't be directly
   included due to issues with macros.  Hence <memory> must be included
   from system.h by defining INCLUDE_MEMORY in any source file using
   make-unique.h.  */

#ifndef INCLUDE_MEMORY
# error "You must define INCLUDE_MEMORY before including system.h to use make-unique.h"
#endif

#include <type_traits>

/* Minimal implementation of make_unique for C++11 compatibility
   (std::make_unique is C++14).  */

template<typename T, typename... Args>
inline typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(Args&&... args)
{
  return std::unique_ptr<T> (new T (std::forward<Args> (args)...));
}

#endif /* ! GCC_MAKE_UNIQUE */
