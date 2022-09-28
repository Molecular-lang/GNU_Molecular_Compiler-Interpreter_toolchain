// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file hash_eq_fn.hpp
 * Contains 2 equivalence functions, one employing a hash value,
 * and one ignoring it.
 */

#ifndef PB_DS_HASH_EQ_FN_HPP
#define PB_DS_HASH_EQ_FN_HPP

#include <utility>
#include <ext/pb_ds/detail/types_traits.hpp>
#include <debug/debug.h>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Primary template.
    template<typename Key, typename Eq_Fn, typename _Alloc, bool Store_Hash>
      struct hash_eq_fn;

    /// Specialization 1 - The client requests that hash values not be stored.
    template<typename Key, typename Eq_Fn, typename _Alloc>
    struct hash_eq_fn<Key, Eq_Fn, _Alloc, false> : public Eq_Fn
    {
      typedef Eq_Fn 					   eq_fn_base;
      typedef typename rebind_traits<_Alloc, Key>::const_reference
	key_const_reference;

      hash_eq_fn() { }

      hash_eq_fn(const Eq_Fn& r_eq_fn) : Eq_Fn(r_eq_fn) { }

      bool
      operator()(key_const_reference r_lhs_key, 
		 key_const_reference r_rhs_key) const
      { return eq_fn_base::operator()(r_lhs_key, r_rhs_key); }

      void
      swap(const hash_eq_fn& other)
      { std::swap((Eq_Fn&)(*this), (Eq_Fn&)other); }
    };


    /// Specialization 2 - The client requests that hash values be stored.
    template<typename Key, class Eq_Fn, class _Alloc>
    struct hash_eq_fn<Key, Eq_Fn, _Alloc, true> : public Eq_Fn
    {
      typedef typename _Alloc::size_type 		   size_type;
      typedef Eq_Fn 					   eq_fn_base;
      typedef typename rebind_traits<_Alloc, Key>::const_reference
	key_const_reference;

      hash_eq_fn() { }

      hash_eq_fn(const Eq_Fn& r_eq_fn) : Eq_Fn(r_eq_fn) { }

      bool
      operator()(key_const_reference r_lhs_key, size_type lhs_hash, 
		 key_const_reference r_rhs_key, size_type rhs_hash) const
      {
	_GLIBCXX_DEBUG_ASSERT(!eq_fn_base::operator()(r_lhs_key, r_rhs_key) 
			      || lhs_hash == rhs_hash);

	return (lhs_hash == rhs_hash && 
		eq_fn_base::operator()(r_lhs_key, r_rhs_key));
      }

      void
      swap(const hash_eq_fn& other)
      { std::swap((Eq_Fn&)(*this), (Eq_Fn&)(other)); }
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif 
