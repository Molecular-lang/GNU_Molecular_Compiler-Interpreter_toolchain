// filebuf with encoding state type -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _EXT_ENC_FILEBUF_H
#define _EXT_ENC_FILEBUF_H 1

#include <fstream>
#include <locale>
#include <ext/codecvt_specializations.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /// class enc_filebuf.
  template<typename _CharT>
    class enc_filebuf
    : public std::basic_filebuf<_CharT, encoding_char_traits<_CharT> >
    {
    public:
      typedef encoding_char_traits<_CharT>     	traits_type;
      typedef typename traits_type::state_type	state_type;
      typedef typename traits_type::pos_type	pos_type;

      enc_filebuf(state_type& __state)
      : std::basic_filebuf<_CharT, encoding_char_traits<_CharT> >()
      { this->_M_state_beg = __state; }

    private:
      // concept requirements:
      // Set state type to something useful.
      // Something more than copyconstructible is needed here, so
      // require default and copy constructible + assignment operator.
      __glibcxx_class_requires(state_type, _SGIAssignableConcept)
    };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
