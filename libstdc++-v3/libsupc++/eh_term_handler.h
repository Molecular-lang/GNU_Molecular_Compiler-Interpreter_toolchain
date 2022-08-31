// -*- C++ -*- default std::terminate handler
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>

/* We default to the talkative, informative handler in a normal hosted
   library.  This pulls in the demangler, the dyn-string utilities, and
   elements of the I/O library.  For a low-memory environment, you can return
   to the earlier "silent death" handler by configuring GCC with
   --disable-libstdcxx-verbose and rebuilding the library.
   In a freestanding environment, we default to this latter approach.  */

#if _GLIBCXX_HOSTED && _GLIBCXX_VERBOSE && __cpp_exceptions
# define _GLIBCXX_DEFAULT_TERM_HANDLER __gnu_cxx::__verbose_terminate_handler
#else
# include <cstdlib>
# define _GLIBCXX_DEFAULT_TERM_HANDLER std::abort
#endif
