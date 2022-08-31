// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <typeinfo>

namespace std {

bad_cast::~bad_cast() _GLIBCXX_USE_NOEXCEPT { }

const char* 
bad_cast::what() const _GLIBCXX_USE_NOEXCEPT
{
  return "std::bad_cast";
}

} // namespace std
