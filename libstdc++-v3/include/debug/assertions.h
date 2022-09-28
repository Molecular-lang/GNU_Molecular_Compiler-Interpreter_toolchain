// Debugging support implementation -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_DEBUG_ASSERTIONS_H
#define _GLIBCXX_DEBUG_ASSERTIONS_H 1

#include <bits/c++config.h>

#ifndef _GLIBCXX_DEBUG

# define _GLIBCXX_DEBUG_ASSERT(_Condition)
# define _GLIBCXX_DEBUG_PEDASSERT(_Condition)
# define _GLIBCXX_DEBUG_ONLY(_Statement)

#endif

#ifndef _GLIBCXX_ASSERTIONS
# define __glibcxx_requires_non_empty_range(_First,_Last)
# define __glibcxx_requires_nonempty()
# define __glibcxx_requires_subscript(_N)
#else

// Verify that [_First, _Last) forms a non-empty iterator range.
# define __glibcxx_requires_non_empty_range(_First,_Last)	\
  __glibcxx_assert(_First != _Last)
# define __glibcxx_requires_subscript(_N)	\
  __glibcxx_assert(_N < this->size())
// Verify that the container is nonempty
# define __glibcxx_requires_nonempty()		\
  __glibcxx_assert(!this->empty())
#endif

#ifdef _GLIBCXX_DEBUG
# define _GLIBCXX_DEBUG_ASSERT(_Condition) __glibcxx_assert(_Condition)

# ifdef _GLIBCXX_DEBUG_PEDANTIC
#  define _GLIBCXX_DEBUG_PEDASSERT(_Condition) _GLIBCXX_DEBUG_ASSERT(_Condition)
# else
#  define _GLIBCXX_DEBUG_PEDASSERT(_Condition)
# endif

# define _GLIBCXX_DEBUG_ONLY(_Statement) _Statement
#endif

#endif // _GLIBCXX_DEBUG_ASSERTIONS
