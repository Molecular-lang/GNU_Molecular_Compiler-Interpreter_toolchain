// std::list utilities implementation -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <list>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  namespace __detail
  {
    void
    _List_node_base::swap(_List_node_base& __x,
			  _List_node_base& __y) _GLIBCXX_USE_NOEXCEPT
    {
      if ( __x._M_next != &__x )
	{
	  if ( __y._M_next != &__y )
	    {
	      // Both __x and __y are not empty.
	      std::swap(__x._M_next,__y._M_next);
	      std::swap(__x._M_prev,__y._M_prev);
	      __x._M_next->_M_prev = __x._M_prev->_M_next = &__x;
	      __y._M_next->_M_prev = __y._M_prev->_M_next = &__y;
	    }
	  else
	    {
	      // __x is not empty, __y is empty.
	      __y._M_next = __x._M_next;
	      __y._M_prev = __x._M_prev;
	      __y._M_next->_M_prev = __y._M_prev->_M_next = &__y;
	      __x._M_next = __x._M_prev = &__x;
	    }
	}
      else if ( __y._M_next != &__y )
	{
	  // __x is empty, __y is not empty.
	  __x._M_next = __y._M_next;
	  __x._M_prev = __y._M_prev;
	  __x._M_next->_M_prev = __x._M_prev->_M_next = &__x;
	  __y._M_next = __y._M_prev = &__y;
	}
    }

    void
    _List_node_base::
    _M_transfer(_List_node_base * const __first,
		_List_node_base * const __last) _GLIBCXX_USE_NOEXCEPT
    {
      __glibcxx_assert(__first != __last);

      if (this != __last)
	{
	  // Remove [first, last) from its old position.
	  __last->_M_prev->_M_next  = this;
	  __first->_M_prev->_M_next = __last;
	  this->_M_prev->_M_next    = __first;

	  // Splice [first, last) into its new position.
	  _List_node_base* const __tmp = this->_M_prev;
	  this->_M_prev                = __last->_M_prev;
	  __last->_M_prev              = __first->_M_prev;
	  __first->_M_prev             = __tmp;
	}
    }

    void
    _List_node_base::_M_reverse() _GLIBCXX_USE_NOEXCEPT
    {
      _List_node_base* __tmp = this;
      do
	{
	  std::swap(__tmp->_M_next, __tmp->_M_prev);

	  // Old next node is now prev.
	  __tmp = __tmp->_M_prev;
	}
      while (__tmp != this);
    }

    void
    _List_node_base::
    _M_hook(_List_node_base* const __position) _GLIBCXX_USE_NOEXCEPT
    {
      this->_M_next = __position;
      this->_M_prev = __position->_M_prev;
      __position->_M_prev->_M_next = this;
      __position->_M_prev = this;
    }

    void
    _List_node_base::_M_unhook() _GLIBCXX_USE_NOEXCEPT
    {
      _List_node_base* const __next_node = this->_M_next;
      _List_node_base* const __prev_node = this->_M_prev;
      __prev_node->_M_next = __next_node;
      __next_node->_M_prev = __prev_node;
    }
  } // namespace __detail

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
