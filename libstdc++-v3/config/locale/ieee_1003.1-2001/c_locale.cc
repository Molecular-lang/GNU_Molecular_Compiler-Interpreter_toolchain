// Wrapper for underlying C-language localization -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.8  Standard locale categories.
//

#include <locale>

namespace std _GLIBCXX_VISIBILITY(default)
{
  void
  locale::facet::_S_create_c_locale(__c_locale&, const char*, __c_locale*)
  { }

  void
  locale::facet::_S_destroy_c_locale(__c_locale&)
  { }

  __c_locale
  locale::facet::_S_clone_c_locale(__c_locale&) throw()
  { return __c_locale(); }

  template<>
    void
    numpunct<char>::_M_initialize_numpunct(__c_locale)
    {
      // "C" locale
      _M_decimal_point = '.';
      _M_thousands_sep = ',';
      _M_grouping = "";
      _M_truename = "true";
      _M_falsename = "false";
    }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    void
    numpunct<wchar_t>::_M_initialize_numpunct(__c_locale)
    {
      // "C" locale
      _M_decimal_point = L'.';
      _M_thousands_sep = L',';
      _M_grouping = "";
      _M_truename = L"true";
      _M_falsename = L"false";
    }
#endif

  template<>
    void
    moneypunct<char>::_M_initialize_moneypunct(__c_locale)
    {
      // "C" locale
      _M_decimal_point = '.';
      _M_thousands_sep = ',';
      _M_grouping = "";
      _M_curr_symbol = string_type();
      _M_positive_sign = string_type();
      _M_negative_sign = string_type();
      _M_frac_digits = 0;
      _M_pos_format = money_base::_S_default_pattern;
      _M_neg_format = money_base::_S_default_pattern;
    }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    void
    moneypunct<wchar_t>::_M_initialize_moneypunct(__c_locale)
    {
      // "C" locale
      _M_decimal_point = L'.';
      _M_thousands_sep = L',';
      _M_grouping = "";
      _M_curr_symbol = string_type();
      _M_positive_sign = string_type();
      _M_negative_sign = string_type();
      _M_frac_digits = 0;
      _M_pos_format = money_base::_S_default_pattern;
      _M_neg_format = money_base::_S_default_pattern;
    }
#endif
}  // namespace std

