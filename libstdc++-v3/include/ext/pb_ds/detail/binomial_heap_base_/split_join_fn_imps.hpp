// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_base_/split_join_fn_imps.hpp
 * Contains an implementation class for a base of binomial heaps.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
template<typename Pred>
void
PB_DS_CLASS_C_DEC::
split(Pred pred, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID_COND((*this),true)
  PB_DS_ASSERT_VALID_COND(other,true)

  other.clear();
  if (base_type::empty())
    {
      PB_DS_ASSERT_VALID_COND((*this),true)
      PB_DS_ASSERT_VALID_COND(other,true)
      return;
    }

  base_type::to_linked_list();
  node_pointer p_out = base_type::prune(pred);
  while (p_out != 0)
    {
      _GLIBCXX_DEBUG_ASSERT(base_type::m_size > 0);
      --base_type::m_size;
      ++other.m_size;

      node_pointer p_next = p_out->m_p_next_sibling;
      p_out->m_p_l_child = p_out->m_p_prev_or_parent = 0;
      p_out->m_metadata = 0;

      p_out->m_p_next_sibling = other.m_p_root;
      if (other.m_p_root != 0)
	other.m_p_root->m_p_prev_or_parent = p_out;

      other.m_p_root = p_out;
      other.m_p_root = other.fix(other.m_p_root);
      p_out = p_next;
    }

  PB_DS_ASSERT_VALID_COND(other,true)
  node_pointer p_cur = base_type::m_p_root;
  base_type::m_p_root = 0;

  while (p_cur != 0)
    {
      node_pointer p_next = p_cur->m_p_next_sibling;
      p_cur->m_p_l_child = p_cur->m_p_prev_or_parent = 0;
      p_cur->m_metadata = 0;
      p_cur->m_p_next_sibling = base_type::m_p_root;

      if (base_type::m_p_root != 0)
	base_type::m_p_root->m_p_prev_or_parent = p_cur;

      base_type::m_p_root = p_cur;
      base_type::m_p_root = fix(base_type::m_p_root);
      p_cur = p_next;
    }

  m_p_max = 0;
  PB_DS_ASSERT_VALID_COND((*this),true)
  PB_DS_ASSERT_VALID_COND(other,true)
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
join(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID_COND((*this),true)
  PB_DS_ASSERT_VALID_COND(other,true)

  node_pointer p_other = other.m_p_root;
  if (p_other != 0)
    do
      {
	node_pointer p_next = p_other->m_p_next_sibling;
	std::swap(p_other->m_p_next_sibling, p_other->m_p_prev_or_parent);
	p_other = p_next;
      }
    while (p_other != 0);

  base_type::m_p_root = join(base_type::m_p_root, other.m_p_root);
  base_type::m_size += other.m_size;
  m_p_max = 0;

  other.m_p_root = 0;
  other.m_size = 0;
  other.m_p_max = 0;

  PB_DS_ASSERT_VALID_COND((*this),true)
  PB_DS_ASSERT_VALID_COND(other,true)
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
join(node_pointer p_lhs, node_pointer p_rhs) const
{
  node_pointer p_ret = 0;
  node_pointer p_cur = 0;

  while (p_lhs != 0 || p_rhs != 0)
    {
      if (p_rhs == 0)
	{
	  if (p_cur == 0)
	    p_ret = p_cur = p_lhs;
	  else
	    {
	      p_cur->m_p_next_sibling = p_lhs;
	      p_lhs->m_p_prev_or_parent = p_cur;
	    }
	  p_cur = p_lhs = 0;
	}
      else if (p_lhs == 0 || p_rhs->m_metadata < p_lhs->m_metadata)
	{
	  if (p_cur == 0)
	    {
	      p_ret = p_cur = p_rhs;
	      p_rhs = p_rhs->m_p_prev_or_parent;
	    }
	  else
	    {
	      p_cur->m_p_next_sibling = p_rhs;
	      p_rhs = p_rhs->m_p_prev_or_parent;
	      p_cur->m_p_next_sibling->m_p_prev_or_parent = p_cur;
	      p_cur = p_cur->m_p_next_sibling;
	    }
	}
      else if (p_lhs->m_metadata < p_rhs->m_metadata)
	{
	  if (p_cur == 0)
	    p_ret = p_cur = p_lhs;
	  else
	    {
	      p_cur->m_p_next_sibling = p_lhs;
	      p_lhs->m_p_prev_or_parent = p_cur;
	      p_cur = p_cur->m_p_next_sibling;
	    }
	  p_lhs = p_cur->m_p_next_sibling;
	}
      else
	{
	  node_pointer p_next_rhs = p_rhs->m_p_prev_or_parent;
	  p_rhs->m_p_next_sibling = p_lhs;
	  p_lhs = fix(p_rhs);
	  p_rhs = p_next_rhs;
	}
    }

  if (p_cur != 0)
    p_cur->m_p_next_sibling = 0;

  if (p_ret != 0)
    p_ret->m_p_prev_or_parent = 0;

  return p_ret;
}
#endif
