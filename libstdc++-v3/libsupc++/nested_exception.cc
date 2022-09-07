// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <exception>

namespace std 
{
  nested_exception::~nested_exception() noexcept = default;
} // namespace std
