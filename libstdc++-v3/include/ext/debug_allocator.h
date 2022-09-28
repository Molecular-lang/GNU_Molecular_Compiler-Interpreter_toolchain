// Allocators -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _DEBUG_ALLOCATOR_H
#define _DEBUG_ALLOCATOR_H 1

#include <stdexcept>
#include <bits/functexcept.h>
#include <ext/alloc_traits.h>

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   *  @brief  A meta-allocator with debugging bits.
   *  @ingroup allocators
   *
   *  This is precisely the allocator defined in the C++03 Standard.
   */
  template<typename _Alloc>
    class debug_allocator
    {
      template<typename> friend class debug_allocator;

      typedef __alloc_traits<_Alloc> _Traits;

    public:
      typedef typename _Traits::size_type       	size_type;
      typedef typename _Traits::difference_type	difference_type;
      typedef typename _Traits::pointer       	pointer;
      typedef typename _Traits::const_pointer    const_pointer;
      typedef typename _Traits::reference       	reference;
      typedef typename _Traits::const_reference  const_reference;
      typedef typename _Traits::value_type       value_type;

      template<typename _Up>
	class rebind
	{
	  typedef typename _Traits::template rebind<_Up>::other __other;

	public:
	  typedef debug_allocator<__other> other;
	};

    private:
      // _M_extra is the number of objects that correspond to the
      // extra space where debug information is stored.
      size_type 		_M_extra;
      
      _Alloc			_M_allocator;

      template<typename _Alloc2,
	       typename = typename __alloc_traits<_Alloc2>::template
			   rebind<value_type>::other>
	struct __convertible
	{ };

      template<typename _Alloc2>
	struct __convertible<_Alloc2, _Alloc>
	{
	  typedef void* __type;
	};

      size_type _S_extra()
      {
	const std::size_t __obj_size = sizeof(value_type);
	return (sizeof(size_type) + __obj_size - 1) / __obj_size; 
      }

    public:
      debug_allocator() : _M_extra(_S_extra()) { }

      template<typename _Alloc2>
	debug_allocator(const debug_allocator<_Alloc2>& __a2,
			typename __convertible<_Alloc2>::__type = 0)
	: _M_extra(_S_extra()), _M_allocator(__a2._M_allocator)  { }

      debug_allocator(const _Alloc& __a)
      : _M_extra(_S_extra()), _M_allocator(__a)  { }

      _GLIBCXX_NODISCARD pointer
      allocate(size_type __n)
      {
        pointer __res = _M_allocator.allocate(__n + _M_extra);      
	size_type* __ps = reinterpret_cast<size_type*>(__res);
	*__ps = __n;
        return __res + _M_extra;
      }

      _GLIBCXX_NODISCARD pointer
      allocate(size_type __n, const void* __hint)
      {
        pointer __res = _M_allocator.allocate(__n + _M_extra, __hint);
	size_type* __ps = reinterpret_cast<size_type*>(__res);
	*__ps = __n;
        return __res + _M_extra;
      }

      void
      deallocate(pointer __p, size_type __n)
      {
	using std::__throw_runtime_error;
	if (__p)
	  {
	    pointer __real_p = __p - _M_extra;
	    if (*reinterpret_cast<size_type*>(__real_p) != __n)
	      __throw_runtime_error("debug_allocator::deallocate wrong size");
	    _M_allocator.deallocate(__real_p, __n + _M_extra);
	  }
	else
	  __throw_runtime_error("debug_allocator::deallocate null pointer");
      }

      void
      construct(pointer __p, const value_type& __val)
      { _Traits::construct(_M_allocator, __p, __val); }

#if __cplusplus >= 201103L
      template<typename _Tp, typename... _Args>
	void
	construct(_Tp* __p, _Args&&... __args)
	{
	  _Traits::construct(_M_allocator, __p,
			     std::forward<_Args>(__args)...);
	}
#endif

      template<typename _Tp>
	void
	destroy(_Tp* __p)
	{ _Traits::destroy(_M_allocator, __p); }

      size_type
      max_size() const throw()
      { return _Traits::max_size(_M_allocator) - _M_extra; }

      template<typename _Alloc2>
	friend bool
	operator==(const debug_allocator& __lhs,
		   const debug_allocator<_Alloc2>& __rhs) _GLIBCXX_NOTHROW
	{ return __lhs._M_allocator == debug_allocator(__rhs)._M_allocator; }

#if __cpp_impl_three_way_comparison < 201907L
      template<typename _Alloc2>
	friend bool
	operator!=(const debug_allocator& __lhs,
		   const debug_allocator<_Alloc2>& __rhs) _GLIBCXX_NOTHROW
	{ return !(__lhs == __rhs); }
#endif
    };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
