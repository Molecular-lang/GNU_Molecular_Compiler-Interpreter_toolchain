// Locale support -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.1  Locales
//

// Default information, may not be appropriate for specific host.

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /// @brief  Base class for ctype.
  struct ctype_base
  {
    // Non-standard typedefs.
    typedef const int* 		__to_type;

    // NB: Offsets into ctype<char>::_M_table force a particular size
    // on the mask type. Because of this, we don't use an enum.
    typedef unsigned int 	mask;
    static const mask upper    	= 1 << 0;
    static const mask lower 	= 1 << 1;
    static const mask alpha 	= 1 << 2;
    static const mask digit 	= 1 << 3;
    static const mask xdigit 	= 1 << 4;
    static const mask space 	= 1 << 5;
    static const mask print 	= 1 << 6;
    static const mask graph 	= (1 << 2) | (1 << 3) | (1 << 9); // alnum|punct
    static const mask cntrl 	= 1 << 8;
    static const mask punct 	= 1 << 9;
    static const mask alnum 	= (1 << 2) | (1 << 3);  // alpha|digit
    static const mask blank	= 1 << 10;
  };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
