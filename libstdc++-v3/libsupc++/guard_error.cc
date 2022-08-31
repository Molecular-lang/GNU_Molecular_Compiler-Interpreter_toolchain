// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include <cxxabi.h>

namespace __gnu_cxx
{
  recursive_init_error::recursive_init_error() noexcept { }
  recursive_init_error::~recursive_init_error() noexcept { }
}
