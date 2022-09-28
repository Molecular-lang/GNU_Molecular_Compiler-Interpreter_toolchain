// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_CAST_H
#define _GLIBCXX_CAST_H 1

namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   * These functions are here to allow containers to support non standard
   * pointer types.  For normal pointers, these resolve to the use of the
   * standard cast operation.  For other types the functions will perform
   * the appropriate cast to/from the custom pointer class so long as that
   * class meets the following conditions:
   * 1) has a typedef element_type which names tehe type it points to.
   * 2) has a get() const method which returns element_type*.
   * 3) has a constructor which can take one element_type* argument.
   */

  /**
   * This type supports the semantics of the pointer cast operators (below.)
   */
  template<typename _ToType>
    struct _Caster
    { typedef typename _ToType::element_type*  type; };

  template<typename _ToType>
    struct _Caster<_ToType*>
    { typedef _ToType*  type; };

  /**
   * Casting operations for cases where _FromType is not a standard pointer.
   * _ToType can be a standard or non-standard pointer.  Given that _FromType
   * is not a pointer, it must have a get() method that returns the standard
   * pointer equivalent of the address it points to, and must have an
   * element_type typedef which names the type it points to.
   */
  template<typename _ToType, typename _FromType>
    inline _ToType
    __static_pointer_cast(const _FromType& __arg)
    { return _ToType(static_cast<typename _Caster<_ToType>::
		     type>(__arg.get())); }

  template<typename _ToType, typename _FromType>
    inline _ToType
    __dynamic_pointer_cast(const _FromType& __arg)
    { return _ToType(dynamic_cast<typename _Caster<_ToType>::
		     type>(__arg.get())); }

  template<typename _ToType, typename _FromType>
    inline _ToType
    __const_pointer_cast(const _FromType& __arg)
    { return _ToType(const_cast<typename _Caster<_ToType>::
		     type>(__arg.get())); }

  template<typename _ToType, typename _FromType>
    inline _ToType
    __reinterpret_pointer_cast(const _FromType& __arg)
    { return _ToType(reinterpret_cast<typename _Caster<_ToType>::
		     type>(__arg.get())); }

  /**
   * Casting operations for cases where _FromType is a standard pointer.
   * _ToType can be a standard or non-standard pointer.
   */
  template<typename _ToType, typename _FromType>
    inline _ToType
    __static_pointer_cast(_FromType* __arg)
    { return _ToType(static_cast<typename _Caster<_ToType>::
		     type>(__arg)); }

  template<typename _ToType, typename _FromType>
    inline _ToType
    __dynamic_pointer_cast(_FromType* __arg)
    { return _ToType(dynamic_cast<typename _Caster<_ToType>::
		     type>(__arg)); }

  template<typename _ToType, typename _FromType>
    inline _ToType
    __const_pointer_cast(_FromType* __arg)
    { return _ToType(const_cast<typename _Caster<_ToType>::
		     type>(__arg)); }

  template<typename _ToType, typename _FromType>
    inline _ToType
    __reinterpret_pointer_cast(_FromType* __arg)
    { return _ToType(reinterpret_cast<typename _Caster<_ToType>::
		     type>(__arg)); }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif // _GLIBCXX_CAST_H
