// Support for <functional> -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <functional>
#include <bits/functexcept.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  void
  __throw_bad_function_call()
  { _GLIBCXX_THROW_OR_ABORT(bad_function_call()); }

  bad_function_call::~bad_function_call() noexcept = default;

  const char*
  bad_function_call::what() const noexcept
  { return "bad_function_call"; }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
