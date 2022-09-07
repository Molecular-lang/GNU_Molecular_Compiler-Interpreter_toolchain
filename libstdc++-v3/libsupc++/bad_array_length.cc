// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <new>

namespace std 
{
// From N3639.  This was voted in and then back out of C++14, and is now
// just here for backward link compatibility with code built with 4.9.
class bad_array_length : public bad_alloc
{
public:
  bad_array_length() throw() { };

  // This declaration is not useless:
  // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
  virtual ~bad_array_length() throw();

  // See comment in eh_exception.cc.
  virtual const char* what() const throw();
};

bad_array_length::~bad_array_length() _GLIBCXX_USE_NOEXCEPT { }

const char*
bad_array_length::what() const _GLIBCXX_USE_NOEXCEPT
{ return "std::bad_array_length"; }

} // namespace std

namespace __cxxabiv1 {

extern "C" void
__cxa_throw_bad_array_length ()
{ _GLIBCXX_THROW_OR_ABORT(std::bad_array_length()); }

} // namespace __cxxabiv1
