// Numeric functions implementation -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/stl_numeric.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{numeric}
 */

#ifndef _STL_NUMERIC_H
#define _STL_NUMERIC_H 1

#include <bits/concept_check.h>
#include <debug/debug.h>
#include <bits/move.h> // For _GLIBCXX_MOVE


namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /** @defgroup numeric_ops Generalized Numeric operations
   *  @ingroup algorithms
   */

#if __cplusplus >= 201103L
  /**
   *  @brief  Create a range of sequentially increasing values.
   *
   *  For each element in the range @p [first,last) assigns @p value and
   *  increments @p value as if by @p ++value.
   *
   *  @param  __first  Start of range.
   *  @param  __last  End of range.
   *  @param  __value  Starting value.
   *  @return  Nothing.
   *  @ingroup numeric_ops
   */
  template<typename _ForwardIterator, typename _Tp>
    _GLIBCXX20_CONSTEXPR
    void
    iota(_ForwardIterator __first, _ForwardIterator __last, _Tp __value)
    {
      // concept requirements
      __glibcxx_function_requires(_Mutable_ForwardIteratorConcept<
				  _ForwardIterator>)
      __glibcxx_function_requires(_ConvertibleConcept<_Tp,
	    typename iterator_traits<_ForwardIterator>::value_type>)
      __glibcxx_requires_valid_range(__first, __last);

      for (; __first != __last; ++__first)
	{
	  *__first = __value;
	  ++__value;
	}
    }
#endif

_GLIBCXX_END_NAMESPACE_VERSION

_GLIBCXX_BEGIN_NAMESPACE_ALGO

#if __cplusplus > 201703L
// _GLIBCXX_RESOLVE_LIB_DEFECTS
// DR 2055. std::move in std::accumulate and other algorithms
# define _GLIBCXX_MOVE_IF_20(_E) std::move(_E)
#else
# define _GLIBCXX_MOVE_IF_20(_E) _E
#endif

  /// @addtogroup numeric_ops
  /// @{

  /**
   *  @brief  Accumulate values in a range.
   *
   *  Accumulates the values in the range [first,last) using operator+().  The
   *  initial value is @a init.  The values are processed in order.
   *
   *  @param  __first  Start of range.
   *  @param  __last  End of range.
   *  @param  __init  Starting value to add other values to.
   *  @return  The final sum.
   */
  template<typename _InputIterator, typename _Tp>
    _GLIBCXX20_CONSTEXPR
    inline _Tp
    accumulate(_InputIterator __first, _InputIterator __last, _Tp __init)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_requires_valid_range(__first, __last);

      for (; __first != __last; ++__first)
	__init = _GLIBCXX_MOVE_IF_20(__init) + *__first;
      return __init;
    }

  /**
   *  @brief  Accumulate values in a range with operation.
   *
   *  Accumulates the values in the range `[first,last)` using the function
   *  object `__binary_op`.  The initial value is `__init`.  The values are
   *  processed in order.
   *
   *  @param  __first  Start of range.
   *  @param  __last  End of range.
   *  @param  __init  Starting value to add other values to.
   *  @param  __binary_op  Function object to accumulate with.
   *  @return  The final sum.
   */
  template<typename _InputIterator, typename _Tp, typename _BinaryOperation>
    _GLIBCXX20_CONSTEXPR
    inline _Tp
    accumulate(_InputIterator __first, _InputIterator __last, _Tp __init,
	       _BinaryOperation __binary_op)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_requires_valid_range(__first, __last);

      for (; __first != __last; ++__first)
	__init = __binary_op(_GLIBCXX_MOVE_IF_20(__init), *__first);
      return __init;
    }

  /**
   *  @brief  Compute inner product of two ranges.
   *
   *  Starting with an initial value of @p __init, multiplies successive
   *  elements from the two ranges and adds each product into the accumulated
   *  value using operator+().  The values in the ranges are processed in
   *  order.
   *
   *  @param  __first1  Start of range 1.
   *  @param  __last1  End of range 1.
   *  @param  __first2  Start of range 2.
   *  @param  __init  Starting value to add other values to.
   *  @return  The final inner product.
   */
  template<typename _InputIterator1, typename _InputIterator2, typename _Tp>
    _GLIBCXX20_CONSTEXPR
    inline _Tp
    inner_product(_InputIterator1 __first1, _InputIterator1 __last1,
		  _InputIterator2 __first2, _Tp __init)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>)
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>)
      __glibcxx_requires_valid_range(__first1, __last1);

      for (; __first1 != __last1; ++__first1, (void)++__first2)
	__init = _GLIBCXX_MOVE_IF_20(__init) + (*__first1 * *__first2);
      return __init;
    }

  /**
   *  @brief  Compute inner product of two ranges.
   *
   *  Starting with an initial value of @p __init, applies @p __binary_op2 to
   *  successive elements from the two ranges and accumulates each result into
   *  the accumulated value using @p __binary_op1.  The values in the ranges are
   *  processed in order.
   *
   *  @param  __first1  Start of range 1.
   *  @param  __last1  End of range 1.
   *  @param  __first2  Start of range 2.
   *  @param  __init  Starting value to add other values to.
   *  @param  __binary_op1  Function object to accumulate with.
   *  @param  __binary_op2  Function object to apply to pairs of input values.
   *  @return  The final inner product.
   */
  template<typename _InputIterator1, typename _InputIterator2, typename _Tp,
	   typename _BinaryOperation1, typename _BinaryOperation2>
    _GLIBCXX20_CONSTEXPR
    inline _Tp
    inner_product(_InputIterator1 __first1, _InputIterator1 __last1,
		  _InputIterator2 __first2, _Tp __init,
		  _BinaryOperation1 __binary_op1,
		  _BinaryOperation2 __binary_op2)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator1>)
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator2>)
      __glibcxx_requires_valid_range(__first1, __last1);

      for (; __first1 != __last1; ++__first1, (void)++__first2)
	__init = __binary_op1(_GLIBCXX_MOVE_IF_20(__init),
			      __binary_op2(*__first1, *__first2));
      return __init;
    }

  /**
   *  @brief  Return list of partial sums
   *
   *  Accumulates the values in the range [first,last) using the @c + operator.
   *  As each successive input value is added into the total, that partial sum
   *  is written to @p __result.  Therefore, the first value in @p __result is
   *  the first value of the input, the second value in @p __result is the sum
   *  of the first and second input values, and so on.
   *
   *  @param  __first  Start of input range.
   *  @param  __last  End of input range.
   *  @param  __result  Output sum.
   *  @return  Iterator pointing just beyond the values written to __result.
   */
  template<typename _InputIterator, typename _OutputIterator>
    _GLIBCXX20_CONSTEXPR
    _OutputIterator
    partial_sum(_InputIterator __first, _InputIterator __last,
		_OutputIterator __result)
    {
      typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
				                         _ValueType>)
      __glibcxx_requires_valid_range(__first, __last);

      if (__first == __last)
	return __result;
      _ValueType __value = *__first;
      *__result = __value;
      while (++__first != __last)
	{
	  __value = _GLIBCXX_MOVE_IF_20(__value) + *__first;
	  *++__result = __value;
	}
      return ++__result;
    }

  /**
   *  @brief  Return list of partial sums
   *
   *  Accumulates the values in the range [first,last) using @p __binary_op.
   *  As each successive input value is added into the total, that partial sum
   *  is written to @p __result.  Therefore, the first value in @p __result is
   *  the first value of the input, the second value in @p __result is the sum
   *  of the first and second input values, and so on.
   *
   *  @param  __first  Start of input range.
   *  @param  __last  End of input range.
   *  @param  __result  Output sum.
   *  @param  __binary_op  Function object.
   *  @return  Iterator pointing just beyond the values written to __result.
   */
  template<typename _InputIterator, typename _OutputIterator,
	   typename _BinaryOperation>
    _GLIBCXX20_CONSTEXPR
    _OutputIterator
    partial_sum(_InputIterator __first, _InputIterator __last,
		_OutputIterator __result, _BinaryOperation __binary_op)
    {
      typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
				                         _ValueType>)
      __glibcxx_requires_valid_range(__first, __last);

      if (__first == __last)
	return __result;
      _ValueType __value = *__first;
      *__result = __value;
      while (++__first != __last)
	{
	  __value = __binary_op(_GLIBCXX_MOVE_IF_20(__value), *__first);
	  *++__result = __value;
	}
      return ++__result;
    }

  /**
   *  @brief  Return differences between adjacent values.
   *
   *  Computes the difference between adjacent values in the range
   *  [first,last) using operator-() and writes the result to @p __result.
   *
   *  @param  __first  Start of input range.
   *  @param  __last  End of input range.
   *  @param  __result  Output sums.
   *  @return  Iterator pointing just beyond the values written to result.
   */
  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // DR 539. partial_sum and adjacent_difference should mention requirements
  template<typename _InputIterator, typename _OutputIterator>
    _GLIBCXX20_CONSTEXPR
    _OutputIterator
    adjacent_difference(_InputIterator __first,
			_InputIterator __last, _OutputIterator __result)
    {
      typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
				                         _ValueType>)
      __glibcxx_requires_valid_range(__first, __last);

      if (__first == __last)
	return __result;
      _ValueType __value = *__first;
      *__result = __value;
      while (++__first != __last)
	{
	  _ValueType __tmp = *__first;
	  *++__result = __tmp - _GLIBCXX_MOVE_IF_20(__value);
	  __value = _GLIBCXX_MOVE(__tmp);
	}
      return ++__result;
    }

  /**
   *  @brief  Return differences between adjacent values.
   *
   *  Computes the difference between adjacent values in the range
   *  [__first,__last) using the function object @p __binary_op and writes the
   *  result to @p __result.
   *
   *  @param  __first  Start of input range.
   *  @param  __last  End of input range.
   *  @param  __result  Output sum.
   *  @param  __binary_op Function object.
   *  @return  Iterator pointing just beyond the values written to result.
   */
  // _GLIBCXX_RESOLVE_LIB_DEFECTS
  // DR 539. partial_sum and adjacent_difference should mention requirements
  template<typename _InputIterator, typename _OutputIterator,
	   typename _BinaryOperation>
    _GLIBCXX20_CONSTEXPR
    _OutputIterator
    adjacent_difference(_InputIterator __first, _InputIterator __last,
			_OutputIterator __result, _BinaryOperation __binary_op)
    {
      typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_function_requires(_OutputIteratorConcept<_OutputIterator,
				                         _ValueType>)
      __glibcxx_requires_valid_range(__first, __last);

      if (__first == __last)
	return __result;
      _ValueType __value = *__first;
      *__result = __value;
      while (++__first != __last)
	{
	  _ValueType __tmp = *__first;
	  *++__result = __binary_op(__tmp, _GLIBCXX_MOVE_IF_20(__value));
	  __value = _GLIBCXX_MOVE(__tmp);
	}
      return ++__result;
    }

  /// @} group numeric_ops

#undef _GLIBCXX_MOVE_IF_20

_GLIBCXX_END_NAMESPACE_ALGO
} // namespace std

#endif /* _STL_NUMERIC_H */
