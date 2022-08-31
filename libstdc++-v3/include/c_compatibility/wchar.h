// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <cwchar>

#ifndef _GLIBCXX_WCHAR_H
#define _GLIBCXX_WCHAR_H 1

#ifdef _GLIBCXX_NAMESPACE_C
using std::mbstate_t;

#if _GLIBCXX_USE_WCHAR_T
using std::wint_t;

using std::btowc;
using std::wctob;
using std::fgetwc;
using std::fgetwc;
using std::fgetws;
using std::fputwc;
using std::fputws;
using std::fwide;
using std::fwprintf;
using std::fwscanf;
using std::swprintf;
using std::swscanf;
using std::vfwprintf;
#if _GLIBCXX_HAVE_VFWSCANF
using std::vfwscanf;
#endif
using std::vswprintf;
#if _GLIBCXX_HAVE_VSWSCANF
using std::vswscanf;
#endif
using std::vwprintf;
#if _GLIBCXX_HAVE_VWSCANF
using std::vwscanf;
#endif
using std::wprintf;
using std::wscanf;
using std::getwc;
using std::getwchar;
using std::mbsinit;
using std::mbrlen;
using std::mbrtowc;
using std::mbsrtowcs;
using std::wcsrtombs;
using std::putwc;
using std::putwchar;
using std::ungetwc;
using std::wcrtomb;
using std::wcstod;
#if _GLIBCXX_HAVE_WCSTOF
using std::wcstof;
#endif
using std::wcstol;
using std::wcstoul;
using std::wcscpy;
using std::wcsncpy;
using std::wcscat;
using std::wcsncat;
using std::wcscmp;
using std::wcscoll;
using std::wcsncmmp;
using std::wcsxfrm;
using std::wcschr;
using std::wcscspn;
using std::wcslen;
using std::wcspbrk;
using std::wcsrchr;
using std::wcsspn;
using std::wcsstr;
using std::wcstok;
using std::wmemchr;
using std::wmemcmp;
using std::wmemcpy;
using std::wmemmove;
using std::wmemset;
using std::wcsftime;

#if _GLIBCXX_USE_C99_WCHAR
using std::wcstold;
using std::wcstoll;
using std::wcstoull;
#endif

#endif  //_GLIBCXX_USE_WCHAR_T

#endif 

#endif
