// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pairing_heap_/split_join_fn_imps.hpp
 * Contains an implementation class for a pairing heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
template<typename Pred>
void
PB_DS_CLASS_C_DEC::
split(Pred pred, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  other.clear();

  if (base_type::empty())
    {
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
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
      p_out->m_p_l_child = p_out->m_p_next_sibling = p_out->m_p_prev_or_parent = 0;

      other.push_imp(p_out);
      p_out = p_next;
    }

  PB_DS_ASSERT_VALID(other)
  node_pointer p_cur = base_type::m_p_root;
  base_type::m_p_root = 0;
  while (p_cur != 0)
    {
      node_pointer p_next = p_cur->m_p_next_sibling;
      p_cur->m_p_l_child = p_cur->m_p_next_sibling = p_cur->m_p_prev_or_parent = 0;

      push_imp(p_cur);
      p_cur = p_next;
    }

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
join(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  if (other.m_p_root == 0)
    {
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return;
    }

  if (base_type::m_p_root == 0)
    base_type::m_p_root = other.m_p_root;
  else if (Cmp_Fn::operator()(base_type::m_p_root->m_value, other.m_p_root->m_value))
    {
      base_type::make_child_of(base_type::m_p_root, other.m_p_root);
      PB_DS_ASSERT_NODE_CONSISTENT(other.m_p_root, false)
      base_type::m_p_root = other.m_p_root;
    }
  else
    {
      base_type::make_child_of(other.m_p_root, base_type::m_p_root);
      PB_DS_ASSERT_NODE_CONSISTENT(base_type::m_p_root, false)
    }

  base_type::m_size += other.m_size;
  other.m_p_root = 0;
  other.m_size = 0;
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}
#endif
