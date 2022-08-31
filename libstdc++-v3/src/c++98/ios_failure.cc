// Iostreams base classes -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:1998: 27.4.2.1.1  Class ios_base::failure
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include <ios>

#if _GLIBCXX_USE_DUAL_ABI && __cpp_rtti
#include <cxxabi.h>
#include <typeinfo>
#endif

#ifdef _GLIBCXX_USE_NLS
# include <libintl.h>
# define _(msgid)   gettext (msgid)
#else
# define _(msgid)   (msgid)
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  ios_base::failure::failure(const string& __str) throw()
  : _M_msg(__str) { }

  ios_base::failure::~failure() throw()
  { }

  const char*
  ios_base::failure::what() const throw()
  { return _M_msg.c_str(); }

#if _GLIBCXX_USE_DUAL_ABI
  // When the dual ABI is enabled __throw_ios_failure() is defined in
  // src/c++11/cxx11-ios_failure.cc
#if __cpp_rtti
  // If RTTI is enabled the exception type thrown will use these functions to
  // construct/destroy a gcc4-compatible ios::failure object in a buffer,
  // and to catch that object via a handler of the gcc4-compatible type.
  void
  __construct_ios_failure(void* buf, const char* msg)
  { ::new(buf) ios_base::failure(msg); }

  void
  __destroy_ios_failure(void* buf)
  { static_cast<ios_base::failure*>(buf)->~failure(); }

  bool
  __is_ios_failure_handler(const __cxxabiv1::__class_type_info* type)
  { return *type == typeid(ios::failure); }

  namespace {
  // C++98-style static assertions to ensure ios::failure fits in a buffer
  // with the same size and alignment as runtime_error:
  typedef char S[1 / (sizeof(ios::failure) <= sizeof(runtime_error))];
  typedef char A[1 / (__alignof(ios::failure) <= __alignof(runtime_error))];
  }
#endif // __cpp_rtti

#else // ! _GLIBCXX_USE_DUAL_ABI

  void
  __throw_ios_failure(const char* __s __attribute__((unused)))
  { _GLIBCXX_THROW_OR_ABORT(ios::failure(_(__s))); }

  void
  __throw_ios_failure(const char* str, int)
  { __throw_ios_failure(str); }

#endif // _GLIBCXX_USE_DUAL_ABI

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
