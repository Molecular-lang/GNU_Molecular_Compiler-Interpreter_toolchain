// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file eq_by_less.hpp
 * Contains an equivalence function.
 */

#ifndef PB_DS_EQ_BY_LESS_HPP
#define PB_DS_EQ_BY_LESS_HPP

#include <utility>
#include <functional>
#include <vector>
#include <assert.h>
#include <ext/pb_ds/detail/types_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Equivalence function.
    template<typename Key, class Cmp_Fn>
    struct eq_by_less : private Cmp_Fn
    {
      bool
      operator()(const Key& r_lhs, const Key& r_rhs) const
      {
	const bool l = Cmp_Fn::operator()(r_lhs, r_rhs);
	const bool g = Cmp_Fn::operator()(r_rhs, r_lhs);
	return !(l || g);
      }
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_EQ_BY_LESS_HPP
