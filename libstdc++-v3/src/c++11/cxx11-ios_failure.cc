// Iostreams base classes -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:2011: 27.5.3.1.1  Class ios_base::failure
//

#define _GLIBCXX_USE_CXX11_ABI 1
#include <ios>
#include <bits/functexcept.h>
#include <cxxabi.h>

#ifdef _GLIBCXX_USE_NLS
# include <libintl.h>
# define _(msgid)   gettext (msgid)
#else
# define _(msgid)   (msgid)
#endif

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  ios_base::failure::failure(const string& __str)
  : system_error(io_errc::stream, __str) { }

  ios_base::failure::failure(const string& __str, const error_code& __ec)
  : system_error(__ec, __str) { }

  ios_base::failure::failure(const char* __str, const error_code& __ec)
  : system_error(__ec, __str) { }

  ios_base::failure::~failure()
  { }

  const char*
  ios_base::failure::what() const throw()
  { return runtime_error::what(); }

#if __cpp_rtti
  // These functions are defined in src/c++98/ios_failure.cc
  extern void __construct_ios_failure(void*, const char*);
  extern void __destroy_ios_failure(void*);
  extern bool __is_ios_failure_handler(const __cxxabiv1::__class_type_info*);

  // The type thrown to report errors during stream buffer operations.
  // In addition to the ios::failure[abi:cxx11] base class it also has a
  // member of the gcc4-compatible ios::failure type (in an opaque buffer).
  struct __ios_failure : std::ios::failure
  {
    __ios_failure(const char* s) : failure(s)
    { __construct_ios_failure(buf, runtime_error::what()); }

    __ios_failure(const char* s, const error_code& e) : failure(s, e)
    { __construct_ios_failure(buf, runtime_error::what()); }

    ~__ios_failure()
    { __destroy_ios_failure(buf); }

    // Use std::runtime_error as a proxy for the gcc4-compatible ios::failure
    // (which can't be declared here because _GLIBCXX_USE_CXX11_ABI == 1).
    // There are assertions in src/c++98/ios_failure.cc to ensure the size
    // and alignment assumptions are valid.
    alignas(runtime_error) unsigned char buf[sizeof(runtime_error)];
  };

  // Custom type info for __ios_failure.
  class __iosfail_type_info : __cxxabiv1::__si_class_type_info
  {
    ~__iosfail_type_info();

    bool
    __do_upcast (const __class_type_info *dst_type,
		 void **obj_ptr) const override;
  };

  __iosfail_type_info::~__iosfail_type_info() = default;

  // This function gets called to see if an exception of type
  // __ios_failure can be upcast to the type in a catch handler.
  bool
  __iosfail_type_info::__do_upcast(const __class_type_info *dst_type,
				   void **obj_ptr) const
  {
    // If the handler is for the gcc4-compatible ios::failure type then
    // catch the object stored in __ios_failure::buf instead of
    // the __ios_failure exception object itself.
    if (__is_ios_failure_handler(dst_type))
      {
	*obj_ptr = static_cast<__ios_failure*>(*obj_ptr)->buf;
	return true;
      }
    // Otherwise proceed as normal to see if the handler matches.
    return __class_type_info::__do_upcast(dst_type, obj_ptr);
  }
#else // ! __cpp_rtti
  using __ios_failure = ios::failure;
#endif

  void
  __throw_ios_failure(const char* __s __attribute__((unused)))
  { _GLIBCXX_THROW_OR_ABORT(__ios_failure(_(__s))); }

  void
  __throw_ios_failure(const char* str __attribute__((unused)),
		      int err __attribute__((unused)))
  {
    _GLIBCXX_THROW_OR_ABORT(__ios_failure(_(str),
	  err ? error_code(err, generic_category()) : io_errc::stream));
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
