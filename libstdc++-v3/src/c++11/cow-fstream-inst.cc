// Explicit instantiation file.

// Please review $(srcdir/SPL-README) for GNU licencing info.

//
// ISO C++ 14882:
//

#define _GLIBCXX_USE_CXX11_ABI 0
#include <fstream>

#if ! _GLIBCXX_USE_DUAL_ABI
# error This file should not be compiled for this configuration.
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template basic_filebuf<char>*
    basic_filebuf<char>::open(const std::string&, ios_base::openmode);
  template
    basic_ifstream<char>::
    basic_ifstream(const std::string&, ios_base::openmode);
  template void
    basic_ifstream<char>::open(const std::string&, ios_base::openmode);
  template
    basic_ofstream<char>::
    basic_ofstream(const std::string&, ios_base::openmode);
  template void
    basic_ofstream<char>::open(const std::string&, ios_base::openmode);
  template
    basic_fstream<char>::basic_fstream(const std::string&, ios_base::openmode);
  template void
    basic_fstream<char>::open(const std::string&, ios_base::openmode);

#ifdef _GLIBCXX_USE_WCHAR_T
  template basic_filebuf<wchar_t>*
    basic_filebuf<wchar_t>::open(const std::string&, ios_base::openmode);
  template
    basic_ifstream<wchar_t>::
    basic_ifstream(const std::string&, ios_base::openmode);
  template void
    basic_ifstream<wchar_t>::open(const std::string&, ios_base::openmode);
  template
    basic_ofstream<wchar_t>::
    basic_ofstream(const std::string&, ios_base::openmode);
  template void
    basic_ofstream<wchar_t>::open(const std::string&, ios_base::openmode);
  template
    basic_fstream<wchar_t>::
    basic_fstream(const std::string&, ios_base::openmode);
  template void
    basic_fstream<wchar_t>::open(const std::string&, ios_base::openmode);
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
