// Locale support -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882: 22.1  Locales
//

// Instantiate locales using COW std::wstring ABI
#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/c++config.h>

#ifdef _GLIBCXX_USE_WCHAR_T
#define C wchar_t
#include "locale-inst.cc"
#endif // _GLIBCXX_USE_WCHAR_T
