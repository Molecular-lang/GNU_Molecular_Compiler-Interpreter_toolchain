// -fno-exceptions Support -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

/** @file bits/exception_defines.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{exception}
 */

#ifndef _EXCEPTION_DEFINES_H
#define _EXCEPTION_DEFINES_H 1

#if ! __cpp_exceptions
// Iff -fno-exceptions, transform error handling code to work without it.
# define __try      if (true)
# define __catch(X) if (false)
# define __throw_exception_again
#else
// Else proceed normally.
# define __try      try
# define __catch(X) catch(X)
# define __throw_exception_again throw
#endif

#endif
