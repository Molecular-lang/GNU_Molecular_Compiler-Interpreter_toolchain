// Namespace declarations for Library Fundamentals TS -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#if __cplusplus >= 201402L
#include <bits/c++config.h>

  /** @defgroup libfund-ts Library Fundamentals TS
   *  @ingroup experimental
   *
   * Components defined by the _C++ Extensions for Library Fundamentals_
   * Technical Specification, versions 1 and 2.
   *
   * - ISO/IEC TS 19568:2015 C++ Extensions for Library Fundamentals
   * - ISO/IEC TS 19568:2017 C++ Extensions for Library Fundamentals, Version 2
   */

#if _GLIBCXX_INLINE_VERSION
namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

namespace chrono
{
namespace experimental
{
inline namespace fundamentals_v1 { }
inline namespace fundamentals_v2 { }
} // namespace experimental
} // namespace chrono

namespace experimental
{
inline namespace fundamentals_v1 { }
inline namespace fundamentals_v2 { }
inline namespace literals { inline namespace string_view_literals { } }
} // namespace experimental

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
#endif
#endif
