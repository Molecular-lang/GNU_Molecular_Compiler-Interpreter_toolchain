// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file probe_fn_base.hpp
 * Contains a probe policy base.
 */

#ifndef PB_DS_PROBE_FN_BASE_HPP
#define PB_DS_PROBE_FN_BASE_HPP

#include <functional>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Probe functor base.
    template<typename _Alloc>
    class probe_fn_base
    {
    protected:
      ~probe_fn_base() { }
    };
} // namespace detail
} // namespace __gnu_pbds

#endif 
