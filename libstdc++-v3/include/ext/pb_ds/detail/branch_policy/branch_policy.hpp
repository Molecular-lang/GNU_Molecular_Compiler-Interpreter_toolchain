// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file branch_policy/branch_policy.hpp
 * Contains a base class for branch policies.
 */

#ifndef PB_DS_BRANCH_POLICY_BASE_HPP
#define PB_DS_BRANCH_POLICY_BASE_HPP

#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/detail/types_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Primary template, base class for branch structure policies.
    template<typename Node_CItr, typename Node_Itr, typename _Alloc>
      struct branch_policy
      {
      protected:
	typedef typename Node_Itr::value_type 		it_type;
	typedef typename std::iterator_traits<it_type>::value_type value_type;
	typedef typename value_type::first_type 	key_type;

	typedef typename remove_const<value_type>::type	rcvalue_type;
	typedef typename remove_const<key_type>::type	rckey_type;

	typedef rebind_traits<_Alloc, rcvalue_type>	rebind_v;
	typedef rebind_traits<_Alloc, rckey_type>	rebind_k;

	typedef	typename rebind_v::reference 		reference;
	typedef	typename rebind_v::const_reference 	const_reference;
	typedef	typename rebind_v::const_pointer	const_pointer;

	typedef	typename rebind_k::const_reference 	key_const_reference;

	static inline key_const_reference
	extract_key(const_reference r_val)
	{ return r_val.first; }

	virtual it_type
	end() = 0;

	it_type
	end_iterator() const
	{ return const_cast<branch_policy*>(this)->end(); }

	virtual
	~branch_policy() { }
      };

    /// Specialization for const iterators.
    template<typename Node_CItr, typename _Alloc>
      struct branch_policy<Node_CItr, Node_CItr, _Alloc>
      {
      protected:
	typedef typename Node_CItr::value_type 		   it_type;
       	typedef typename std::iterator_traits<it_type>::value_type value_type;
	typedef typename remove_const<value_type>::type		   rcvalue_type;
	typedef rebind_traits<_Alloc, rcvalue_type>	rebind_v;
	typedef	typename rebind_v::reference 		reference;
	typedef	typename rebind_v::const_reference 	const_reference;
	typedef	typename rebind_v::const_pointer	const_pointer;

	typedef value_type 				key_type;
	typedef	typename rebind_v::const_reference 	key_const_reference;

	static inline key_const_reference
	extract_key(const_reference r_val)
	{ return r_val; }

	virtual it_type
	end() const = 0;

	it_type
	end_iterator() const
	{ return end(); }

	virtual
	~branch_policy() { }
      };
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_BRANCH_POLICY_BASE_HPP
