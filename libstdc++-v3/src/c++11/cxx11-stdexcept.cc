// Methods for Exception Support for -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 19.1  Exception classes
//

#define _GLIBCXX_USE_CXX11_ABI 1
#include <stdexcept>

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // These constructors take an abi-tagged std::string and use it to
  // initialize an untagged COW std::string in _M_msg.

  logic_error::logic_error(const string& __arg)
  : _M_msg(__arg) { }

  runtime_error::runtime_error(const string& __arg)
  : _M_msg(__arg) { }

  // These constructors take an abi-tagged std::string and pass it to the
  // base class constructors defined above.

  domain_error::domain_error(const string& __arg)
  : logic_error(__arg) { }

  invalid_argument::invalid_argument(const string& __arg)
  : logic_error(__arg) { }

  length_error::length_error(const string& __arg)
  : logic_error(__arg) { }

  out_of_range::out_of_range(const string& __arg)
  : logic_error(__arg) { }

  range_error::range_error(const string& __arg)
  : runtime_error(__arg) { }

  overflow_error::overflow_error(const string& __arg)
  : runtime_error(__arg) { }

  underflow_error::underflow_error(const string& __arg)
  : runtime_error(__arg) { }

  // Converting constructor from ABI-tagged std::string to COW string.
  __cow_string::__cow_string(const string& s)
  : __cow_string(s.c_str(), s.length()) { }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
