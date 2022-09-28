// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pat_trie_/find_fn_imps.hpp
 * Contains an implementation class for pat_trie.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key)
{
  PB_DS_ASSERT_VALID((*this))
  node_pointer p_nd = find_imp(r_key);

  if (p_nd == 0 || p_nd->m_type != leaf_node)
    {
      PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
      return end();
    }

  if (synth_access_traits::equal_keys(PB_DS_V2F(static_cast<leaf_pointer>(p_nd)->value()), r_key))
    {
      PB_DS_CHECK_KEY_EXISTS(r_key)
      return iterator(p_nd);
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
  return end();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
find(key_const_reference r_key) const
{
  PB_DS_ASSERT_VALID((*this))

  node_const_pointer p_nd = const_cast<PB_DS_CLASS_C_DEC* >(this)->find_imp(r_key);

  if (p_nd == 0 || p_nd->m_type != leaf_node)
    {
      PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
      return end();
    }

  if (synth_access_traits::equal_keys(PB_DS_V2F(static_cast<leaf_const_pointer>(p_nd)->value()), r_key))
    {
      PB_DS_CHECK_KEY_EXISTS(r_key)
      return const_iterator(const_cast<node_pointer>(p_nd));
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(r_key)
  return end();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
find_imp(key_const_reference r_key)
{
  if (empty())
    return 0;

  typename synth_access_traits::const_iterator b_it =
    synth_access_traits::begin(r_key);
  typename synth_access_traits::const_iterator e_it =
    synth_access_traits::end(r_key);

  node_pointer p_nd = m_p_head->m_p_parent;
  _GLIBCXX_DEBUG_ASSERT(p_nd != 0);

  while (p_nd->m_type != leaf_node)
    {
      _GLIBCXX_DEBUG_ASSERT(p_nd->m_type == i_node);
      node_pointer p_next_nd = static_cast<inode_pointer>(p_nd)->get_child_node(b_it,  e_it,  this);

      if (p_next_nd == 0)
	return p_nd;
      p_nd = p_next_nd;
    }
  return p_nd;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
lower_bound_imp(key_const_reference r_key)
{
  if (empty())
    return (m_p_head);

  node_pointer p_nd = m_p_head->m_p_parent;
  _GLIBCXX_DEBUG_ASSERT(p_nd != 0);

  typename PB_DS_CLASS_C_DEC::a_const_iterator b_it =
    synth_access_traits::begin(r_key);

  typename PB_DS_CLASS_C_DEC::a_const_iterator e_it =
    synth_access_traits::end(r_key);

  size_type checked_ind = 0;
  while (true)
    {
      if (p_nd->m_type == leaf_node)
        {
	  if (!synth_access_traits::cmp_keys(PB_DS_V2F(static_cast<leaf_const_pointer>(p_nd)->value()), r_key))
	    return p_nd;
	  iterator it(p_nd);
	  ++it;
	  return it.m_p_nd;
        }

      _GLIBCXX_DEBUG_ASSERT(p_nd->m_type == i_node);
      const size_type new_checked_ind =
	static_cast<inode_pointer>(p_nd)->get_e_ind();

      p_nd =
	static_cast<inode_pointer>(p_nd)->get_lower_bound_child_node(                b_it, e_it, checked_ind, this);
      checked_ind = new_checked_ind;
    }
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
lower_bound(key_const_reference r_key)
{ return point_iterator(lower_bound_imp(r_key)); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
lower_bound(key_const_reference r_key) const
{
  return point_const_iterator(const_cast<PB_DS_CLASS_C_DEC* >(this)->lower_bound_imp(r_key));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
upper_bound(key_const_reference r_key)
{
  point_iterator l_bound_it = lower_bound(r_key);

  _GLIBCXX_DEBUG_ASSERT(l_bound_it == end() ||
		   !synth_access_traits::cmp_keys(PB_DS_V2F(*l_bound_it),
						    r_key));

  if (l_bound_it == end() ||
      synth_access_traits::cmp_keys(r_key, PB_DS_V2F(*l_bound_it)))
    return l_bound_it;

  return ++l_bound_it;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_const_iterator
PB_DS_CLASS_C_DEC::
upper_bound(key_const_reference r_key) const
{
  point_const_iterator l_bound_it = lower_bound(r_key);

  _GLIBCXX_DEBUG_ASSERT(l_bound_it == end() ||
		   !synth_access_traits::cmp_keys(PB_DS_V2F(*l_bound_it),
						    r_key));

  if (l_bound_it == end() ||
      synth_access_traits::cmp_keys(r_key, PB_DS_V2F(*l_bound_it)))
    return l_bound_it;
  return ++l_bound_it;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::a_const_iterator
PB_DS_CLASS_C_DEC::
pref_begin(node_const_pointer p_nd)
{
  if (p_nd->m_type == leaf_node)
    return (synth_access_traits::begin(PB_DS_V2F(static_cast<leaf_const_pointer>(p_nd)->value())));

  _GLIBCXX_DEBUG_ASSERT(p_nd->m_type == i_node);
  return static_cast<inode_const_pointer>(p_nd)->pref_b_it();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::a_const_iterator
PB_DS_CLASS_C_DEC::
pref_end(node_const_pointer p_nd)
{
  if (p_nd->m_type == leaf_node)
    return (synth_access_traits::end(PB_DS_V2F(static_cast<leaf_const_pointer>(p_nd)->value())));

  _GLIBCXX_DEBUG_ASSERT(p_nd->m_type == i_node);
  return static_cast<inode_const_pointer>(p_nd)->pref_e_it();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::leaf_const_pointer
PB_DS_CLASS_C_DEC::
leftmost_descendant(node_const_pointer p_nd)
{
  if (p_nd->m_type == leaf_node)
    return static_cast<leaf_const_pointer>(p_nd);
  return static_cast<inode_const_pointer>(p_nd)->leftmost_descendant();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::leaf_pointer
PB_DS_CLASS_C_DEC::
leftmost_descendant(node_pointer p_nd)
{
  if (p_nd->m_type == leaf_node)
    return static_cast<leaf_pointer>(p_nd);
  return static_cast<inode_pointer>(p_nd)->leftmost_descendant();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::leaf_const_pointer
PB_DS_CLASS_C_DEC::
rightmost_descendant(node_const_pointer p_nd)
{
  if (p_nd->m_type == leaf_node)
    return static_cast<leaf_const_pointer>(p_nd);
  return static_cast<inode_const_pointer>(p_nd)->rightmost_descendant();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::leaf_pointer
PB_DS_CLASS_C_DEC::
rightmost_descendant(node_pointer p_nd)
{
  if (p_nd->m_type == leaf_node)
    return static_cast<leaf_pointer>(p_nd);
  return static_cast<inode_pointer>(p_nd)->rightmost_descendant();
}

#endif
