// Compatibility symbols for previous versions, list bits -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/move.h>

#ifndef _GLIBCXX_BEGIN_NAMESPACE_COMPAT
# define _GLIBCXX_BEGIN_NAMESPACE_COMPAT
#endif

#ifndef _GLIBCXX_END_NAMESPACE_COMPAT
# define _GLIBCXX_END_NAMESPACE_COMPAT
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_COMPAT

  struct _List_node_base
  {
    _List_node_base* _M_next;
    _List_node_base* _M_prev;

    static void
    swap(_List_node_base& __x, _List_node_base& __y) throw ();

    void
    transfer(_List_node_base * const __first,
	     _List_node_base * const __last) throw ();

    void
    reverse() throw ();

    void
    hook(_List_node_base * const __position) throw ();

    void
    unhook() throw ();
  };

  void
  _List_node_base::swap(_List_node_base& __x, _List_node_base& __y) throw()
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
  _List_node_base::transfer(_List_node_base * const __first,
			    _List_node_base * const __last) throw ()
  {
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
  _List_node_base::reverse() throw ()
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
  _List_node_base::hook(_List_node_base* const __position) throw ()
  {
    this->_M_next = __position;
    this->_M_prev = __position->_M_prev;
    __position->_M_prev->_M_next = this;
    __position->_M_prev = this;
  }

  void
  _List_node_base::unhook() throw ()
  {
    _List_node_base* const __next_node = this->_M_next;
    _List_node_base* const __prev_node = this->_M_prev;
    __prev_node->_M_next = __next_node;
    __next_node->_M_prev = __prev_node;
  }

_GLIBCXX_END_NAMESPACE_COMPAT

} // namespace std
