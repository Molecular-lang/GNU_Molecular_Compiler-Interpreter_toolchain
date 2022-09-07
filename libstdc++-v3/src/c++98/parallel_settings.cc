// Default settings for parallel mode -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <parallel/settings.h>

namespace
{
  __gnu_parallel::_Settings s;
}

namespace __gnu_parallel
{
  const _Settings&
  _Settings::get() throw()
  { return s; }

  // XXX MT
  void
  _Settings::set(_Settings& obj) throw()
  { s = obj; }
}
