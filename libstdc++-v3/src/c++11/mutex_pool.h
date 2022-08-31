// Mutex pool used to limit contention -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

namespace __gnu_internal _GLIBCXX_VISIBILITY(hidden)
{
  const unsigned char mask = 0xf;
  const unsigned char invalid = mask + 1;

  /* Returns different instances of __mutex depending on the passed index
   * in order to limit contention.
   */
  __gnu_cxx::__mutex& get_mutex(unsigned char i);
}
