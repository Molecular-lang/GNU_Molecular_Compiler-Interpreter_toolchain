// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_EXCEPTION_HPP
#define PB_DS_EXCEPTION_HPP

#include <bits/c++config.h>
#include <stdexcept>
#include <cstdlib>

namespace __gnu_pbds
{
  /**
   *  @defgroup exceptions-pbds Exceptions
   *  @ingroup pbds
   *  @{
   */

  /// Base class for exceptions.
  struct container_error : public std::logic_error
  {
    container_error()
    : std::logic_error(__N("__gnu_pbds::container_error")) { }
  };

  /// An entry cannot be inserted into a container object for logical
  /// reasons (not, e.g., if memory is unabvailable, in which case
  /// the allocator_type's exception will be thrown).
  struct insert_error : public container_error { };

  /// A join cannot be performed logical reasons (i.e., the ranges of
  /// the two container objects being joined overlaps.
  struct join_error : public container_error { };

  /// A container cannot be resized.
  struct resize_error : public container_error { };

  inline void
  __throw_container_error()
  { _GLIBCXX_THROW_OR_ABORT(container_error()); }

  inline void
  __throw_insert_error()
  { _GLIBCXX_THROW_OR_ABORT(insert_error()); }

  inline void
  __throw_join_error()
  { _GLIBCXX_THROW_OR_ABORT(join_error()); }

  inline void
  __throw_resize_error()
  { _GLIBCXX_THROW_OR_ABORT(resize_error()); }
  ///@}
} // namespace __gnu_pbds

#endif
