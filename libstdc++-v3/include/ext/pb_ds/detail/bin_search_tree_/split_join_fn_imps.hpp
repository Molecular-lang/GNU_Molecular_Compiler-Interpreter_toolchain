// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file bin_search_tree_/split_join_fn_imps.hpp
 * Contains an implementation class for bin_search_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
bool
PB_DS_CLASS_C_DEC::
join_prep(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
  if (other.m_size == 0)
    return false;

  if (m_size == 0)
    {
      value_swap(other);
      return false;
    }

  const bool greater =
    Cmp_Fn::operator()(PB_DS_V2F(m_p_head->m_p_right->m_value),
		       PB_DS_V2F(other.m_p_head->m_p_left->m_value));

  const bool lesser =
    Cmp_Fn::operator()(PB_DS_V2F(other.m_p_head->m_p_right->m_value),
		       PB_DS_V2F(m_p_head->m_p_left->m_value));

  if (!greater && !lesser)
    __throw_join_error();

  if (lesser)
    value_swap(other);

  m_size += other.m_size;
  _GLIBCXX_DEBUG_ONLY(debug_base::join(other);)
  return true;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
join_finish(PB_DS_CLASS_C_DEC& other)
{
  initialize_min_max();
  other.initialize();
}

PB_DS_CLASS_T_DEC
bool
PB_DS_CLASS_C_DEC::
split_prep(key_const_reference r_key, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
  other.clear();

  if (m_size == 0)
    {
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return false;
    }

  if (Cmp_Fn::operator()(r_key, PB_DS_V2F(m_p_head->m_p_left->m_value)))
    {
      value_swap(other);
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return false;
    }

  if (!Cmp_Fn::operator()(r_key, PB_DS_V2F(m_p_head->m_p_right->m_value)))
    {
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return false;
    }

  if (m_size == 1)
    {
      value_swap(other);
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return false;
    }

  _GLIBCXX_DEBUG_ONLY(debug_base::split(r_key,(Cmp_Fn& )(*this), other);)
  return true;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
split_finish(PB_DS_CLASS_C_DEC& other)
{
  other.initialize_min_max();
  other.m_size = std::distance(other.begin(), other.end());
  m_size -= other.m_size;
  initialize_min_max();
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
recursive_count(node_pointer p) const
{
  if (p == 0)
    return 0;
  return 1 + recursive_count(p->m_p_left) + recursive_count(p->m_p_right);
}

#endif
