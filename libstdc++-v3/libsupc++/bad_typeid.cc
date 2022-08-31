// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <typeinfo>

namespace std {

bad_typeid::~bad_typeid() _GLIBCXX_USE_NOEXCEPT { }

const char* 
bad_typeid::what() const _GLIBCXX_USE_NOEXCEPT
{
  return "std::bad_typeid";
}

} // namespace std
