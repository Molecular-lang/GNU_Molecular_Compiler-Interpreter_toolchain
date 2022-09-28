// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/equally_split.h
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Johannes Singler.

#ifndef _GLIBCXX_PARALLEL_EQUALLY_SPLIT_H
#define _GLIBCXX_PARALLEL_EQUALLY_SPLIT_H 1

namespace __gnu_parallel
{
  /** @brief function to split a sequence into parts of almost equal size.
   *
   *  The resulting sequence __s of length __num_threads+1 contains the
   *  splitting positions when splitting the range [0,__n) into parts of
   *  almost equal size (plus minus 1).  The first entry is 0, the last
   *  one n. There may result empty parts.
   *  @param __n Number of elements
   *  @param __num_threads Number of parts
   *  @param __s Splitters
   *  @returns End of __splitter sequence, i.e. @c __s+__num_threads+1 */
  template<typename _DifferenceType, typename _OutputIterator>
    _OutputIterator
    __equally_split(_DifferenceType __n, _ThreadIndex __num_threads,
		    _OutputIterator __s)
    {
      _DifferenceType __chunk_length = __n / __num_threads;
      _DifferenceType __num_longer_chunks = __n % __num_threads;
      _DifferenceType __pos = 0;
      for (_ThreadIndex __i = 0; __i < __num_threads; ++__i)
	{
	  *__s++ = __pos;
	  __pos += ((__i < __num_longer_chunks)
		    ? (__chunk_length + 1) : __chunk_length);
	}
      *__s++ = __n;
      return __s;
    }

  /** @brief function to split a sequence into parts of almost equal size.
   *
   *  Returns the position of the splitting point between
   *  thread number __thread_no (included) and
   *  thread number __thread_no+1 (excluded).
   *  @param __n Number of elements
   *  @param __num_threads Number of parts
   *  @param __thread_no Number of threads
   *  @returns splitting point */
  template<typename _DifferenceType>
    _DifferenceType
    __equally_split_point(_DifferenceType __n,
			  _ThreadIndex __num_threads,
			  _ThreadIndex __thread_no)
    {
      _DifferenceType __chunk_length = __n / __num_threads;
      _DifferenceType __num_longer_chunks = __n % __num_threads;
      if (__thread_no < __num_longer_chunks)
	return __thread_no * (__chunk_length + 1);
      else
	return __num_longer_chunks * (__chunk_length + 1)
          + (__thread_no - __num_longer_chunks) * __chunk_length;
    }
}

#endif /* _GLIBCXX_PARALLEL_EQUALLY_SPLIT_H */
