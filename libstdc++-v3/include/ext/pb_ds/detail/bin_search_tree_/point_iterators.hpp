// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file bin_search_tree_/point_iterators.hpp
 * Contains an implementation class for bin_search_tree_.
 */

#ifndef PB_DS_BIN_SEARCH_TREE_FIND_ITERATORS_HPP
#define PB_DS_BIN_SEARCH_TREE_FIND_ITERATORS_HPP

#include <ext/pb_ds/tag_and_trait.hpp>
#include <debug/debug.h>

namespace __gnu_pbds
{
  namespace detail
  {

#define PB_DS_TREE_CONST_IT_C_DEC					\
    bin_search_tree_const_it_<						\
						Node_Pointer,		\
						Value_Type,		\
						Pointer,		\
						Const_Pointer,		\
						Reference,		\
						Const_Reference,	\
						Is_Forward_Iterator,	\
						_Alloc>

#define PB_DS_TREE_CONST_ODIR_IT_C_DEC					\
    bin_search_tree_const_it_<						\
						Node_Pointer,		\
						Value_Type,		\
						Pointer,		\
						Const_Pointer,		\
						Reference,		\
						Const_Reference,	\
						!Is_Forward_Iterator,	\
						_Alloc>

#define PB_DS_TREE_IT_C_DEC						\
    bin_search_tree_it_<						\
						Node_Pointer,		\
						Value_Type,		\
						Pointer,		\
						Const_Pointer,		\
						Reference,		\
						Const_Reference,	\
						Is_Forward_Iterator,	\
						_Alloc>

#define PB_DS_TREE_ODIR_IT_C_DEC					\
    bin_search_tree_it_<						\
							Node_Pointer,	\
							Value_Type,	\
							Pointer,	\
							Const_Pointer,	\
							Reference,	\
							Const_Reference, \
							!Is_Forward_Iterator, \
							_Alloc>

    /// Const iterator.
    template<typename Node_Pointer,
	     typename Value_Type,
	     typename Pointer,
	     typename Const_Pointer,
	     typename Reference,
	     typename Const_Reference,
	     bool Is_Forward_Iterator,
	     typename _Alloc>
    class bin_search_tree_const_it_
    {
    public:
      typedef std::bidirectional_iterator_tag 		iterator_category;
      typedef typename _Alloc::difference_type 	difference_type;
      typedef Value_Type 				value_type;
      typedef Pointer 					pointer;
      typedef Const_Pointer 				const_pointer;
      typedef Reference 				reference;
      typedef Const_Reference 				const_reference;

      inline
      bin_search_tree_const_it_(const Node_Pointer p_nd = 0) 
      : m_p_nd(const_cast<Node_Pointer>(p_nd))
      { }

      inline
      bin_search_tree_const_it_(const PB_DS_TREE_CONST_ODIR_IT_C_DEC& other) 
      : m_p_nd(other.m_p_nd)
      { }

      inline
      PB_DS_TREE_CONST_IT_C_DEC& 
      operator=(const PB_DS_TREE_CONST_IT_C_DEC& other)
      {
	m_p_nd = other.m_p_nd;
	return *this;
      }

      inline
      PB_DS_TREE_CONST_IT_C_DEC& 
      operator=(const PB_DS_TREE_CONST_ODIR_IT_C_DEC& other)
      {
	m_p_nd = other.m_p_nd;
	return *this;
      }

      inline const_pointer
      operator->() const
      {
	_GLIBCXX_DEBUG_ASSERT(m_p_nd != 0);
	return &m_p_nd->m_value;
      }

      inline const_reference
      operator*() const
      {
	_GLIBCXX_DEBUG_ASSERT(m_p_nd != 0);
	return m_p_nd->m_value;
      }

      inline bool
      operator==(const PB_DS_TREE_CONST_IT_C_DEC & other) const
      { return m_p_nd == other.m_p_nd; }

      inline bool
      operator==(const PB_DS_TREE_CONST_ODIR_IT_C_DEC & other) const
      { return m_p_nd == other.m_p_nd; }

      inline bool
      operator!=(const PB_DS_TREE_CONST_IT_C_DEC& other) const
      { return m_p_nd != other.m_p_nd; }

      inline bool
      operator!=(const PB_DS_TREE_CONST_ODIR_IT_C_DEC& other) const
      { return m_p_nd != other.m_p_nd; }

      inline PB_DS_TREE_CONST_IT_C_DEC& 
      operator++()
      {
	_GLIBCXX_DEBUG_ASSERT(m_p_nd != 0);
	inc(integral_constant<int,Is_Forward_Iterator>());
	return *this;
      }

      inline PB_DS_TREE_CONST_IT_C_DEC
      operator++(int)
      {
	PB_DS_TREE_CONST_IT_C_DEC ret_it(m_p_nd);
	operator++();
	return ret_it;
      }

      inline PB_DS_TREE_CONST_IT_C_DEC& 
      operator--()
      {
	dec(integral_constant<int,Is_Forward_Iterator>());
	return *this;
      }

      inline PB_DS_TREE_CONST_IT_C_DEC
      operator--(int)
      {
	PB_DS_TREE_CONST_IT_C_DEC ret_it(m_p_nd);
	operator--();
	return ret_it;
      }

    protected:
      inline void
      inc(false_type)
      { dec(true_type()); }

      void
      inc(true_type)
      {
	if (m_p_nd->special()&& 
	    m_p_nd->m_p_parent->m_p_parent == m_p_nd)
	  {
	    m_p_nd = m_p_nd->m_p_left;
	    return;
	  }

	if (m_p_nd->m_p_right != 0)
	  {
	    m_p_nd = m_p_nd->m_p_right;
	    while (m_p_nd->m_p_left != 0)
	      m_p_nd = m_p_nd->m_p_left;
	    return;
	  }

	Node_Pointer p_y = m_p_nd->m_p_parent;
	while (m_p_nd == p_y->m_p_right)
	  {
	    m_p_nd = p_y;
	    p_y = p_y->m_p_parent;
	  }

	if (m_p_nd->m_p_right != p_y)
	  m_p_nd = p_y;
      }

      inline void
      dec(false_type)
      { inc(true_type()); }

      void
      dec(true_type)
      {
	if (m_p_nd->special() && m_p_nd->m_p_parent->m_p_parent == m_p_nd)
	  {
	    m_p_nd = m_p_nd->m_p_right;
	    return;
	  }

	if (m_p_nd->m_p_left != 0)
	  {
	    Node_Pointer p_y = m_p_nd->m_p_left;
	    while (p_y->m_p_right != 0)
	      p_y = p_y->m_p_right;
	    m_p_nd = p_y;
	    return;
	  }

	Node_Pointer p_y = m_p_nd->m_p_parent;
	while (m_p_nd == p_y->m_p_left)
	  {
	    m_p_nd = p_y;
	    p_y = p_y->m_p_parent;
	  }
	if (m_p_nd->m_p_left != p_y)
	  m_p_nd = p_y;
      }

    public:
      Node_Pointer m_p_nd;
    };

    /// Iterator.
    template<typename Node_Pointer,
	     typename Value_Type,
	     typename Pointer,
	     typename Const_Pointer,
	     typename Reference,
	     typename Const_Reference,
	     bool Is_Forward_Iterator,
	     typename _Alloc>
    class bin_search_tree_it_ : public PB_DS_TREE_CONST_IT_C_DEC
    {
    public:
      inline
      bin_search_tree_it_(const Node_Pointer p_nd = 0) 
      : PB_DS_TREE_CONST_IT_C_DEC((Node_Pointer)p_nd)
      { }

      inline
      bin_search_tree_it_(const PB_DS_TREE_ODIR_IT_C_DEC& other) 
      : PB_DS_TREE_CONST_IT_C_DEC(other.m_p_nd)
      { }

      inline
      PB_DS_TREE_IT_C_DEC& 
      operator=(const PB_DS_TREE_IT_C_DEC& other)
      {
	base_it_type::m_p_nd = other.m_p_nd;
	return *this;
      }

      inline
      PB_DS_TREE_IT_C_DEC& 
      operator=(const PB_DS_TREE_ODIR_IT_C_DEC& other)
      {
	base_it_type::m_p_nd = other.m_p_nd;
	return *this;
      }

      inline typename PB_DS_TREE_CONST_IT_C_DEC::pointer
      operator->() const
      {
	_GLIBCXX_DEBUG_ASSERT(base_it_type::m_p_nd != 0);
	return &base_it_type::m_p_nd->m_value;
      }

      inline typename PB_DS_TREE_CONST_IT_C_DEC::reference
      operator*() const
      {
	_GLIBCXX_DEBUG_ASSERT(base_it_type::m_p_nd != 0);
	return base_it_type::m_p_nd->m_value;
      }

      inline PB_DS_TREE_IT_C_DEC& 
      operator++()
      {
	PB_DS_TREE_CONST_IT_C_DEC:: operator++();
	return *this;
      }

      inline PB_DS_TREE_IT_C_DEC
      operator++(int)
      {
	PB_DS_TREE_IT_C_DEC ret_it(base_it_type::m_p_nd);
	operator++();
	return ret_it;
      }

      inline PB_DS_TREE_IT_C_DEC& 
      operator--()
      {
	PB_DS_TREE_CONST_IT_C_DEC:: operator--();
	return *this;
      }

      inline PB_DS_TREE_IT_C_DEC
      operator--(int)
      {
	PB_DS_TREE_IT_C_DEC ret_it(base_it_type::m_p_nd);
	operator--();
	return ret_it;
      }

    protected:
      typedef PB_DS_TREE_CONST_IT_C_DEC base_it_type;
    };

#undef PB_DS_TREE_CONST_IT_C_DEC
#undef PB_DS_TREE_CONST_ODIR_IT_C_DEC
#undef PB_DS_TREE_IT_C_DEC
#undef PB_DS_TREE_ODIR_IT_C_DEC

  } // namespace detail
} // namespace __gnu_pbds

#endif 
