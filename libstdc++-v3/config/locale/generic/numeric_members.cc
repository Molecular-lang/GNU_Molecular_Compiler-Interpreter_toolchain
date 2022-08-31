// std::numpunct implementation details, generic version -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

//
// ISO C++ 14882: 22.2.3.1.2  numpunct virtual functions
//

#include <locale>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<>
    void
    numpunct<char>::_M_initialize_numpunct(__c_locale)
    {
      // "C" locale
      if (!_M_data)
	_M_data = new __numpunct_cache<char>;

      _M_data->_M_grouping = "";
      _M_data->_M_grouping_size = 0;
      _M_data->_M_use_grouping = false;

      _M_data->_M_decimal_point = '.';
      _M_data->_M_thousands_sep = ',';

      for (size_t __i = 0; __i < __num_base::_S_oend; ++__i)
	_M_data->_M_atoms_out[__i] = __num_base::_S_atoms_out[__i];

      for (size_t __i = 0; __i < __num_base::_S_iend; ++__i)
	_M_data->_M_atoms_in[__i] = __num_base::_S_atoms_in[__i];

      _M_data->_M_truename = "true";
      _M_data->_M_truename_size = 4;
      _M_data->_M_falsename = "false";
      _M_data->_M_falsename_size = 5;
    }

  template<>
    numpunct<char>::~numpunct()
    { delete _M_data; }

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    void
    numpunct<wchar_t>::_M_initialize_numpunct(__c_locale)
    {
      // "C" locale
      if (!_M_data)
	_M_data = new __numpunct_cache<wchar_t>;

      _M_data->_M_grouping = "";
      _M_data->_M_grouping_size = 0;
      _M_data->_M_use_grouping = false;

      _M_data->_M_decimal_point = L'.';
      _M_data->_M_thousands_sep = L',';

      // Use ctype::widen code without the facet...
      for (size_t __i = 0; __i < __num_base::_S_oend; ++__i)
	_M_data->_M_atoms_out[__i] =
	  static_cast<wchar_t>(__num_base::_S_atoms_out[__i]);

      for (size_t __i = 0; __i < __num_base::_S_iend; ++__i)
	_M_data->_M_atoms_in[__i] =
	  static_cast<wchar_t>(__num_base::_S_atoms_in[__i]);

      _M_data->_M_truename = L"true";
      _M_data->_M_truename_size = 4;
      _M_data->_M_falsename = L"false";
      _M_data->_M_falsename_size = 5;
    }

  template<>
    numpunct<wchar_t>::~numpunct()
    { delete _M_data; }
#endif

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

