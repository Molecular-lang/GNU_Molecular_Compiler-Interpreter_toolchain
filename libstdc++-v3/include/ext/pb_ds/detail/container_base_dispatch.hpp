// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_ASSOC_CNTNR_BASE_DS_DISPATCHER_HPP
#define PB_DS_ASSOC_CNTNR_BASE_DS_DISPATCHER_HPP

#include <ext/typelist.h>

#define PB_DS_ASSERT_VALID(X)						\
  _GLIBCXX_DEBUG_ONLY(X.assert_valid(__FILE__, __LINE__);)

#define PB_DS_DEBUG_VERIFY(_Cond)					\
  _GLIBCXX_DEBUG_VERIFY_AT(_Cond,					\
			   _M_message(#_Cond" assertion from %1;:%2;")	\
			   ._M_string(__FILE__)._M_integer(__LINE__)	\
			   ,__file,__line)

#define PB_DS_CHECK_KEY_EXISTS(_Key)					\
  _GLIBCXX_DEBUG_ONLY(debug_base::check_key_exists(_Key, __FILE__, __LINE__);)

#define PB_DS_CHECK_KEY_DOES_NOT_EXIST(_Key)				\
  _GLIBCXX_DEBUG_ONLY(debug_base::check_key_does_not_exist(_Key,	\
							   __FILE__, __LINE__);)

#define PB_DS_DATA_TRUE_INDICATOR
#define PB_DS_V2F(X) (X).first
#define PB_DS_V2S(X) (X).second
#define PB_DS_EP2VP(X)& ((X)->m_value)
#include <ext/pb_ds/detail/list_update_map_/lu_map_.hpp>
#include <ext/pb_ds/detail/bin_search_tree_/bin_search_tree_.hpp>
#include <ext/pb_ds/detail/rb_tree_map_/rb_tree_.hpp>
#include <ext/pb_ds/detail/splay_tree_/splay_tree_.hpp>
#include <ext/pb_ds/detail/ov_tree_map_/ov_tree_map_.hpp>
#include <ext/pb_ds/detail/cc_hash_table_map_/cc_ht_map_.hpp>
#include <ext/pb_ds/detail/gp_hash_table_map_/gp_ht_map_.hpp>
#include <ext/pb_ds/detail/pat_trie_/pat_trie_.hpp>
#undef PB_DS_DATA_TRUE_INDICATOR
#undef PB_DS_V2F
#undef PB_DS_V2S
#undef PB_DS_EP2VP

#define PB_DS_DATA_FALSE_INDICATOR
#define PB_DS_V2F(X) (X)
#define PB_DS_V2S(X) Mapped_Data()
#define PB_DS_EP2VP(X)& ((X)->m_value.first)
#include <ext/pb_ds/detail/list_update_map_/lu_map_.hpp>
#include <ext/pb_ds/detail/bin_search_tree_/bin_search_tree_.hpp>
#include <ext/pb_ds/detail/rb_tree_map_/rb_tree_.hpp>
#include <ext/pb_ds/detail/splay_tree_/splay_tree_.hpp>
#include <ext/pb_ds/detail/ov_tree_map_/ov_tree_map_.hpp>
#include <ext/pb_ds/detail/cc_hash_table_map_/cc_ht_map_.hpp>
#include <ext/pb_ds/detail/gp_hash_table_map_/gp_ht_map_.hpp>
#include <ext/pb_ds/detail/pat_trie_/pat_trie_.hpp>
#undef PB_DS_DATA_FALSE_INDICATOR
#undef PB_DS_V2F
#undef PB_DS_V2S
#undef PB_DS_EP2VP

#undef PB_DS_CHECK_KEY_DOES_NOT_EXIST
#undef PB_DS_CHECK_KEY_EXISTS
#undef PB_DS_DEBUG_VERIFY
#undef PB_DS_ASSERT_VALID

namespace __gnu_pbds
{
namespace detail
{
  /// Specialization for list-update map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, Mapped, _Alloc, list_update_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef lu_map<Key, Mapped, at0t, _Alloc, at1t>	type;
    };

  /// Specialization for list-update set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, list_update_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef lu_set<Key, null_type, at0t, _Alloc, at1t> type;
    };

  /// Specialization for PATRICIA trie map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
  struct container_base_dispatch<Key, Mapped, _Alloc, pat_trie_tag, Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      typedef pat_trie_map<Key, Mapped, at1t, _Alloc> 		type;
    };

  /// Specialization for PATRICIA trie set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, pat_trie_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef pat_trie_set<Key, null_type, at1t, _Alloc> type;
    };

  /// Specialization for R-B tree map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, Mapped, _Alloc, rb_tree_tag, Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef rb_tree_map<Key, Mapped, at0t, at1t, _Alloc> 	type;
    };

  /// Specialization for R-B tree set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, rb_tree_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      typedef rb_tree_set<Key, null_type, at0t, at1t, _Alloc> type;
    };

  /// Specialization splay tree map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
  struct container_base_dispatch<Key, Mapped, _Alloc, splay_tree_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef splay_tree_map<Key, Mapped, at0t, at1t, _Alloc> 	type;
    };

  /// Specialization splay tree set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, splay_tree_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef splay_tree_set<Key, null_type, at0t, at1t, _Alloc> type;
  };

    /// Specialization ordered-vector tree map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, Mapped, _Alloc, ov_tree_tag, Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef ov_tree_map<Key, Mapped, at0t, at1t, _Alloc> 	type;
  };

    /// Specialization ordered-vector tree set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, ov_tree_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;

    public:
      /// Dispatched type.
      typedef ov_tree_set<Key, null_type, at0t, at1t, _Alloc> type;
  };

    /// Specialization colision-chaining hash map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, Mapped, _Alloc, cc_hash_tag, Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 2>	at2;
      typedef typename at2::type			    	at2t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 3>	at3;
      typedef typename at3::type				at3t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 4> 	at4;
      typedef typename at4::type			    	at4t;

    public:
      /// Dispatched type.
      typedef cc_ht_map<Key, Mapped, at0t, at1t, _Alloc, 
			at3t::value, at4t, at2t> 	       	type;
  };

    /// Specialization colision-chaining hash set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, cc_hash_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 2>	at2;
      typedef typename at2::type			    	at2t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 3>	at3;
      typedef typename at3::type				at3t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 4> 	at4;
      typedef typename at4::type			    	at4t;

    public:
      /// Dispatched type.
      typedef cc_ht_set<Key, null_type, at0t, at1t, _Alloc,
				 at3t::value, at4t, at2t>    	type;
  };

    /// Specialization general-probe hash map.
  template<typename Key, typename Mapped, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, Mapped, _Alloc, gp_hash_tag, Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 2>	at2;
      typedef typename at2::type			    	at2t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 3>	at3;
      typedef typename at3::type				at3t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 4> 	at4;
      typedef typename at4::type			    	at4t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 5> 	at5;
      typedef typename at5::type			    	at5t;

    public:
      /// Dispatched type.
      typedef gp_ht_map<Key, Mapped, at0t, at1t, _Alloc, 
			at3t::value, at4t, at5t, at2t> 		type;
  };

    /// Specialization general-probe hash set.
  template<typename Key, typename _Alloc, typename Policy_Tl>
    struct container_base_dispatch<Key, null_type, _Alloc, gp_hash_tag,
				   Policy_Tl>
    {
    private:
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 0>	at0;
      typedef typename at0::type			    	at0t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 1> 	at1;
      typedef typename at1::type			    	at1t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 2>	at2;
      typedef typename at2::type			    	at2t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 3>	at3;
      typedef typename at3::type				at3t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 4> 	at4;
      typedef typename at4::type			    	at4t;
      typedef __gnu_cxx::typelist::at_index<Policy_Tl, 5> 	at5;
      typedef typename at5::type			    	at5t;

    public:
      /// Dispatched type.
      typedef gp_ht_set<Key, null_type, at0t, at1t, _Alloc,
			at3t::value, at4t, at5t, at2t>		type;
  };
} // namespace detail
} // namespace __gnu_pbds

#endif
