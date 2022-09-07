// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <new>

namespace std 
{

bad_array_new_length::~bad_array_new_length() _GLIBCXX_USE_NOEXCEPT { }

const char*
bad_array_new_length::what() const _GLIBCXX_USE_NOEXCEPT
{ return "std::bad_array_new_length"; }

} // namespace std
