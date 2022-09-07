// -*- C++ -*- Exception handling routines for catching.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <typeinfo>
#include <cxxabi.h>
#include "unwind-cxx.h"

namespace __cxxabiv1
{

// Returns the type_info for the currently handled exception [15.3/8], or
// null if there is none.
extern "C"
std::type_info *__cxa_current_exception_type () _GLIBCXX_NOTHROW
{
  __cxa_eh_globals *globals = __cxa_get_globals ();
  __cxa_exception *header = globals->caughtExceptions;
  if (header)
    {
      if (__is_dependent_exception (header->unwindHeader.exception_class))
        {
          __cxa_dependent_exception *de =
            __get_dependent_exception_from_ue (&header->unwindHeader);
          header = __get_exception_header_from_obj (de->primaryException);
        }
      return header->exceptionType;
    }
  else
    return 0;
}

} // namespace __cxxabiv1
