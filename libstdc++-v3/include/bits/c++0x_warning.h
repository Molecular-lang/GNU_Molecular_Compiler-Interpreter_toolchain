// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/c++0x_warning.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{iosfwd}
 */

#ifndef _CXX0X_WARNING_H
#define _CXX0X_WARNING_H 1

#if __cplusplus < 201103L
#error This file requires compiler and library support \
for the ISO C++ 2011 standard. This support must be enabled \
with the -std=c++11 or -std=gnu++11 compiler options.
#endif

#endif
