// Underlying io library details -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

// c_io_stdio.h - Defines for using "C" stdio.h

#ifndef _GLIBCXX_CXX_IO_H
#define _GLIBCXX_CXX_IO_H 1

#include <cstdio>
#include <bits/gthr.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  typedef __gthread_mutex_t __c_lock;

  // for basic_file.h
  typedef FILE __c_file;

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
