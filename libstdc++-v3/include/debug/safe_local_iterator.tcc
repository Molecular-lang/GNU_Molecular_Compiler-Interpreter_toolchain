// Debugging iterator implementation (out of line) -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_DEBUG_SAFE_LOCAL_ITERATOR_TCC
#define _GLIBCXX_DEBUG_SAFE_LOCAL_ITERATOR_TCC 1

namespace __gnu_debug
{
  template<typename _Iterator, typename _Sequence>
    typename _Distance_traits<_Iterator>::__type
    _Safe_local_iterator<_Iterator, _Sequence>::
    _M_get_distance_to(const _Safe_local_iterator& __rhs) const
    {
      if (base() == __rhs.base())
	return { 0, __dp_exact };

      if (_M_is_begin())
	{
	  if (__rhs._M_is_end())
	    return
	      {
		_M_get_sequence()->bucket_size(bucket()),
		__dp_exact
	      };

	  return { 1, __dp_sign };
	}

      if (_M_is_end())
	{
	  if (__rhs._M_is_begin())
	    return
	      {
		-_M_get_sequence()->bucket_size(bucket()),
		__dp_exact
	      };

	  return { -1, __dp_sign };
	}

      if (__rhs._M_is_begin())
	return { -1, __dp_sign };

      if (__rhs._M_is_end())
	return { 1, __dp_sign };

      return { 1, __dp_equality };
    }

  template<typename _Iterator, typename _Sequence>
    bool
    _Safe_local_iterator<_Iterator, _Sequence>::
    _M_valid_range(const _Safe_local_iterator& __rhs,
		std::pair<difference_type, _Distance_precision>& __dist) const
    {
      if (!_M_can_compare(__rhs))
	return false;

      if (bucket() != __rhs.bucket())
	return false;

      /* Determine if we can order the iterators without the help of
	 the container */
      __dist = _M_get_distance_to(__rhs);
      switch (__dist.second)
	{
	case __dp_equality:
	  if (__dist.first == 0)
	    return true;
	  break;

	case __dp_sign:
	case __dp_exact:
	  return __dist.first >= 0;
	}

      // Assume that this is a valid range; we can't check anything else
      return true;
    }
} // namespace __gnu_debug

#endif
