// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file trie_policy/sample_trie_access_traits.hpp
 * Contains a sample probe policy.
 */

#ifndef PB_DS_SAMPLE_TRIE_E_ACCESS_TRAITS_HPP
#define PB_DS_SAMPLE_TRIE_E_ACCESS_TRAITS_HPP

namespace __gnu_pbds
{
  /// A sample trie element access traits.
  struct sample_trie_access_traits
  {
    typedef std::size_t 		       		size_type;
    typedef std::string 			       	key_type;

    typedef typename rebind_traits<_Alloc, key_type>::const_reference
      key_const_reference;
    typedef std::string::const_iterator 		const_iterator;

    /// Element type.
    typedef char 				       	e_type;

    enum
      {
	max_size = 4
      };

    /// Returns a const_iterator to the first element of r_key.
    inline static const_iterator
    begin(key_const_reference);

    /// Returns a const_iterator to the after-last element of r_key.
    inline static const_iterator
    end(key_const_reference);

    /// Maps an element to a position.
    inline static size_type
    e_pos(e_type);
  };
}
#endif // #ifndef PB_DS_SAMPLE_TRIE_E_ACCESS_TRAITS_HPP
