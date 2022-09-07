// Wrapper for underlying C-language localization -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.8  Standard locale categories.
//

#include <clocale>
#include <langinfo.h>		// For codecvt
#include <iconv.h>		// For codecvt using iconv, iconv_t
#include <nl_types.h> 		// For messages

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  typedef int* __c_locale;

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

