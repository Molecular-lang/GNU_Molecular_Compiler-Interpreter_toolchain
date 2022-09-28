// Debugging support implementation -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_DEBUG_STL_ITERATOR_H
#define _GLIBCXX_DEBUG_STL_ITERATOR_H 1

#include <debug/helper_functions.h>

namespace __gnu_debug
{
  // Help Debug mode to see through reverse_iterator.
  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline bool
    __valid_range(const std::reverse_iterator<_Iterator>& __first,
		  const std::reverse_iterator<_Iterator>& __last,
		  typename _Distance_traits<_Iterator>::__type& __dist)
    {
      return __gnu_debug::__valid_range(__last.base(), __first.base(), __dist);
    }

  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline typename _Distance_traits<_Iterator>::__type
    __get_distance(const std::reverse_iterator<_Iterator>& __first,
		   const std::reverse_iterator<_Iterator>& __last)
    { return __gnu_debug::__get_distance(__last.base(), __first.base()); }

  template<typename _Iterator, typename _Size>
    _GLIBCXX20_CONSTEXPR
    inline bool
    __can_advance(const std::reverse_iterator<_Iterator>& __it, _Size __n)
    { return __gnu_debug::__can_advance(__it.base(), -__n); }

  template<typename _Iterator, typename _Diff>
    _GLIBCXX20_CONSTEXPR
    inline bool
    __can_advance(const std::reverse_iterator<_Iterator>& __it,
		  const std::pair<_Diff, _Distance_precision>& __dist,
		  int __way)
    { return __gnu_debug::__can_advance(__it.base(), __dist, -__way); }

  template<typename _Iterator, typename _Sequence>
    _GLIBCXX20_CONSTEXPR
    inline std::reverse_iterator<_Iterator>
    __base(const std::reverse_iterator<_Safe_iterator<
	     _Iterator, _Sequence, std::random_access_iterator_tag> >& __it)
    { return std::reverse_iterator<_Iterator>(__it.base().base()); }

#if __cplusplus < 201103L
  template<typename _Iterator>
    struct _Unsafe_type<std::reverse_iterator<_Iterator> >
    {
      typedef typename _Unsafe_type<_Iterator>::_Type _UnsafeType;
      typedef std::reverse_iterator<_UnsafeType> _Type;
    };

  template<typename _Iterator>
    inline std::reverse_iterator<typename _Unsafe_type<_Iterator>::_Type>
    __unsafe(const std::reverse_iterator<_Iterator>& __it)
    {
      typedef typename _Unsafe_type<_Iterator>::_Type _UnsafeType;
      return std::reverse_iterator<_UnsafeType>(__unsafe(__it.base()));
    }
#else
  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline auto
    __unsafe(const std::reverse_iterator<_Iterator>& __it)
    -> decltype(std::__make_reverse_iterator(__unsafe(__it.base())))
    { return std::__make_reverse_iterator(__unsafe(__it.base())); }
#endif

#if __cplusplus >= 201103L
  // Help Debug mode to see through move_iterator.
  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline bool
    __valid_range(const std::move_iterator<_Iterator>& __first,
		  const std::move_iterator<_Iterator>& __last,
		  typename _Distance_traits<_Iterator>::__type& __dist)
    {
      return __gnu_debug::__valid_range(__first.base(), __last.base(), __dist);
    }

  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline typename _Distance_traits<_Iterator>::__type
    __get_distance(const std::move_iterator<_Iterator>& __first,
		   const std::move_iterator<_Iterator>& __last)
    { return __gnu_debug::__get_distance(__first.base(), __last.base()); }

  template<typename _Iterator, typename _Size>
    _GLIBCXX20_CONSTEXPR
    inline bool
    __can_advance(const std::move_iterator<_Iterator>& __it, _Size __n)
    { return __gnu_debug::__can_advance(__it.base(), __n); }

  template<typename _Iterator, typename _Diff>
    _GLIBCXX20_CONSTEXPR
    inline bool
    __can_advance(const std::move_iterator<_Iterator>& __it,
		  const std::pair<_Diff, _Distance_precision>& __dist,
		  int __way)
    { return __gnu_debug::__can_advance(__it.base(), __dist, __way); }

  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline auto
    __unsafe(const std::move_iterator<_Iterator>& __it)
    -> decltype(std::make_move_iterator(__unsafe(__it.base())))
    { return std::make_move_iterator(__unsafe(__it.base())); }

  template<typename _Iterator>
    _GLIBCXX20_CONSTEXPR
    inline auto
    __base(const std::move_iterator<_Iterator>& __it)
    -> decltype(std::make_move_iterator(__base(__it.base())))
    { return std::make_move_iterator(__base(__it.base())); }
#endif
}

#endif
