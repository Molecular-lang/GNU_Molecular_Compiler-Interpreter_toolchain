// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <cuchar>

#ifndef _GLIBCXX_UCHAR_H
#define _GLIBCXX_UCHAR_H 1

#ifdef _GLIBCXX_NAMESPACE_C

#if (_GLIBCXX_USE_CHAR8_T \
     && (_GLIBCXX_USE_UCHAR_C8RTOMB_MBRTOC8_FCHAR8_T \
	 || (__cplusplus >= 202002 \
	     && _GLIBCXX_USE_UCHAR_C8RTOMB_MBRTOC8_CXX20)))
using std::mbrtoc8;
using std::c8rtomb;
#endif // _GLIBCXX_USE_CHAR8_T

#if _GLIBCXX_USE_C11_UCHAR_CXX11
using std::mbrtoc16;
using std::c16rtomb;
using std::mbrtoc32;
using std::c32rtomb;
#endif // _GLIBCXX_USE_C11_UCHAR_CXX11

#endif // _GLIBCXX_NAMESPACE_C

#endif // _GLIBCXX_UCHAR_H
