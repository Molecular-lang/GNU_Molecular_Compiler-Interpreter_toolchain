// Methods for Exception Support for -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 19.1  Exception classes
//

// All exception classes still use the classic COW std::string.
#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <stdexcept>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  logic_error::logic_error(const string& __arg)
  : exception(), _M_msg(__arg) { }

  logic_error::~logic_error() _GLIBCXX_USE_NOEXCEPT { }

  const char*
  logic_error::what() const _GLIBCXX_USE_NOEXCEPT
  { return _M_msg.c_str(); }

  domain_error::domain_error(const string& __arg)
  : logic_error(__arg) { }

  domain_error::~domain_error() _GLIBCXX_USE_NOEXCEPT { }

  invalid_argument::invalid_argument(const string& __arg)
  : logic_error(__arg) { }

  invalid_argument::~invalid_argument() _GLIBCXX_USE_NOEXCEPT { }

  length_error::length_error(const string& __arg)
  : logic_error(__arg) { }

  length_error::~length_error() _GLIBCXX_USE_NOEXCEPT { }

  out_of_range::out_of_range(const string& __arg)
  : logic_error(__arg) { }

  out_of_range::~out_of_range() _GLIBCXX_USE_NOEXCEPT { }

  runtime_error::runtime_error(const string& __arg)
  : exception(), _M_msg(__arg) { }

  runtime_error::~runtime_error() _GLIBCXX_USE_NOEXCEPT { }

  const char*
  runtime_error::what() const _GLIBCXX_USE_NOEXCEPT
  { return _M_msg.c_str(); }

  range_error::range_error(const string& __arg)
  : runtime_error(__arg) { }

  range_error::~range_error() _GLIBCXX_USE_NOEXCEPT { }

  overflow_error::overflow_error(const string& __arg)
  : runtime_error(__arg) { }

  overflow_error::~overflow_error() _GLIBCXX_USE_NOEXCEPT { }

  underflow_error::underflow_error(const string& __arg)
  : runtime_error(__arg) { }

  underflow_error::~underflow_error() _GLIBCXX_USE_NOEXCEPT { }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
