// std::iostream_category() definition -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:2011: 27.5.6.5  Error reporting [error.reporting]
//

#define _GLIBCXX_USE_CXX11_ABI 1
#include <ios>

#if __has_cpp_attribute(clang::require_constant_initialization)
#  define __constinit [[clang::require_constant_initialization]]
#endif

namespace
{
  struct io_error_category final : std::error_category
  {
    const char*
    name() const noexcept final
    { return "iostream"; }

    _GLIBCXX_DEFAULT_ABI_TAG
    std::string
    message(int __ec) const final
    {
      std::string __msg;
      switch (std::io_errc(__ec))
      {
      case std::io_errc::stream:
          __msg = "iostream error";
          break;
      default:
          __msg = "Unknown error";
          break;
      }
      return __msg;
    }
  };

  struct constant_init
  {
    union {
      unsigned char unused;
      io_error_category cat;
    };
    constexpr constant_init() : cat() { }
    ~constant_init() { /* do nothing, union member is not destroyed */ }
  };

  __constinit constant_init io_category_instance{};
} // namespace

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  const error_category&
  iostream_category() noexcept
  { return io_category_instance.cat; }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
