// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <cwctype>

#ifndef _GLIBCXX_CWCTYPE_H
#define _GLIBCXX_CWCTYPE_H 1

#ifdef _GLIBCXX_NAMESPACE_C
using std::wctype_t;
using std::wctrans_t;
using std::iswalpha;
using std::iswupper;
using std::iswlower;
using std::iswdigit;
using std::iswxdigit;
using std::iswalnum;
using std::iswspace;
using std::iswpunct;
using std::iswprint;
using std::iswgraph;
using std::iswcntrl;
using std::iswctype;
using std::towctrans;
using std::towlower;
using std::towupper;
using std::wctrans;
using std::wctype;
#endif

#endif
