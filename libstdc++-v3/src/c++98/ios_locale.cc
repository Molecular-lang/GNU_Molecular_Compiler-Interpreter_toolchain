// Iostreams base classes -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 27.4  Iostreams base classes
//

#include <ios>
#include <locale>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // Called only by basic_ios<>::init.
  void
  ios_base::_M_init() throw()
  {
    // NB: May be called more than once
    _M_precision = 6;
    _M_width = 0;
    _M_flags = skipws | dec;
    _M_ios_locale = locale();
  }

  // 27.4.2.3  ios_base locale functions
  locale
  ios_base::imbue(const locale& __loc) throw()
  {
    locale __old = _M_ios_locale;
    _M_ios_locale = __loc;
    _M_call_callbacks(imbue_event);
    return __old;
  }

  // Explicit instantiations for basic_ios are done in src/c++11/ios.cc
  // and so do not include this member, which is only defined for C++98.
  template basic_ios<char>::operator void*() const;
#ifdef _GLIBCXX_USE_WCHAR_T
  template basic_ios<wchar_t>::operator void*() const;
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
