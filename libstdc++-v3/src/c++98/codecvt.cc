// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <locale>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // Definitions for locale::id of standard facets that are specialized.
 locale::id codecvt<char, char, mbstate_t>::id;

#ifdef _GLIBCXX_USE_WCHAR_T
  locale::id codecvt<wchar_t, char, mbstate_t>::id;
#endif

  codecvt<char, char, mbstate_t>::
  codecvt(size_t __refs)
  : __codecvt_abstract_base<char, char, mbstate_t>(__refs),
  _M_c_locale_codecvt(_S_get_c_locale())
  { }

  codecvt<char, char, mbstate_t>::
  codecvt(__c_locale __cloc, size_t __refs)
  : __codecvt_abstract_base<char, char, mbstate_t>(__refs),
  _M_c_locale_codecvt(_S_clone_c_locale(__cloc))
  { }

  codecvt<char, char, mbstate_t>::
  ~codecvt()
  { _S_destroy_c_locale(_M_c_locale_codecvt); }

  codecvt_base::result
  codecvt<char, char, mbstate_t>::
  do_out(state_type&, const intern_type* __from,
	 const intern_type*, const intern_type*& __from_next,
	 extern_type* __to, extern_type*,
	 extern_type*& __to_next) const
  {
    // _GLIBCXX_RESOLVE_LIB_DEFECTS
    // According to the resolution of DR19, "If returns noconv [...]
    // there are no changes to the values in [to, to_limit)."
    __from_next = __from;
    __to_next = __to;
    return noconv;
  }

  codecvt_base::result
  codecvt<char, char, mbstate_t>::
  do_unshift(state_type&, extern_type* __to,
             extern_type*, extern_type*& __to_next) const
  {
    __to_next = __to;
    return noconv;
  }

  codecvt_base::result
  codecvt<char, char, mbstate_t>::
  do_in(state_type&, const extern_type* __from,
	const extern_type*, const extern_type*& __from_next,
	intern_type* __to, intern_type*, intern_type*& __to_next) const
  {
    // _GLIBCXX_RESOLVE_LIB_DEFECTS
    // According to the resolution of DR19, "If returns noconv [...]
    // there are no changes to the values in [to, to_limit)."
    __from_next = __from;
    __to_next = __to;
    return noconv;
  }

  int
  codecvt<char, char, mbstate_t>::
  do_encoding() const throw()
  { return 1; }

  bool
  codecvt<char, char, mbstate_t>::
  do_always_noconv() const throw()
  { return true; }

  int
  codecvt<char, char, mbstate_t>::
  do_length (state_type&, const extern_type* __from,
	     const extern_type* __end, size_t __max) const
  {
    size_t __d = static_cast<size_t>(__end - __from);
    return std::min(__max, __d);
  }

  int
  codecvt<char, char, mbstate_t>::
  do_max_length() const throw()
  { return 1; }

#ifdef _GLIBCXX_USE_WCHAR_T
  // codecvt<wchar_t, char, mbstate_t> required specialization
  codecvt<wchar_t, char, mbstate_t>::
  codecvt(size_t __refs)
  : __codecvt_abstract_base<wchar_t, char, mbstate_t>(__refs),
  _M_c_locale_codecvt(_S_get_c_locale())
  { }

  codecvt<wchar_t, char, mbstate_t>::
  codecvt(__c_locale __cloc, size_t __refs)
  : __codecvt_abstract_base<wchar_t, char, mbstate_t>(__refs),
  _M_c_locale_codecvt(_S_clone_c_locale(__cloc))
  { }

  codecvt<wchar_t, char, mbstate_t>::
  ~codecvt()
  { _S_destroy_c_locale(_M_c_locale_codecvt); }

  codecvt_base::result
  codecvt<wchar_t, char, mbstate_t>::
  do_unshift(state_type&, extern_type* __to,
	     extern_type*, extern_type*& __to_next) const
  {
    // XXX Probably wrong for stateful encodings
    __to_next = __to;
    return noconv;
  }

  bool
  codecvt<wchar_t, char, mbstate_t>::
  do_always_noconv() const throw()
  { return false; }
#endif //  _GLIBCXX_USE_WCHAR_T

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
