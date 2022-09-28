// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/checkers.h
 *  @brief Routines for checking the correctness of algorithm results.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Johannes Singler.

#ifndef _GLIBCXX_PARALLEL_CHECKERS_H
#define _GLIBCXX_PARALLEL_CHECKERS_H 1

#include <cstdio>
#include <bits/stl_algobase.h>
#include <bits/stl_function.h>

namespace __gnu_parallel
{
  /**
   * @brief Check whether @c [__begin, @c __end) is sorted according
   * to @c __comp.
   * @param __begin Begin iterator of sequence.
   * @param __end End iterator of sequence.
   * @param __comp Comparator.
   * @return @c true if sorted, @c false otherwise.
   */
  template<typename _IIter, typename _Compare>
    bool
    __is_sorted(_IIter __begin, _IIter __end, _Compare __comp)
    {
      if (__begin == __end)
        return true;

      _IIter __current(__begin), __recent(__begin);

      for (__current++; __current != __end; __current++)
        {
          if (__comp(*__current, *__recent))
            {
              return false;
            }
          __recent = __current;
        }

      return true;
    }
}

#endif /* _GLIBCXX_PARALLEL_CHECKERS_H */
