// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binary_heap_/insert_fn_imps.hpp
 * Contains an implementation class for a binary_heap.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::point_iterator
PB_DS_CLASS_C_DEC::
push(const_reference r_val)
{
  PB_DS_ASSERT_VALID((*this))
  insert_value(r_val, s_no_throw_copies_ind);
  push_heap();
  PB_DS_ASSERT_VALID((*this))
  return point_iterator(m_a_entries);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
insert_value(value_type val, true_type)
{
  resize_for_insert_if_needed();
  m_a_entries[m_size++] = val;
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
insert_value(const_reference r_val, false_type)
{
  resize_for_insert_if_needed();
  pointer p_new = s_value_allocator.allocate(1);
  cond_dealtor_t cond(p_new);
  new (p_new) value_type(r_val);
  cond.set_no_action();
  m_a_entries[m_size++] = p_new;
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
resize_for_insert_if_needed()
{
  if (!resize_policy::resize_needed_for_grow(m_size))
    {
      _GLIBCXX_DEBUG_ASSERT(m_size < m_actual_size);
      return;
    }

  const size_type new_size = resize_policy::get_new_size_for_grow();
  entry_pointer new_entries = s_entry_allocator.allocate(new_size);
  resize_policy::notify_grow_resize();

  std::copy(m_a_entries, m_a_entries + m_size, new_entries);
  s_entry_allocator.deallocate(m_a_entries, m_actual_size);
  m_actual_size = new_size;
  m_a_entries = new_entries;
  make_heap();
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
modify(point_iterator it, const_reference r_new_val)
{
  PB_DS_ASSERT_VALID((*this))
  swap_value_imp(it.m_p_e, r_new_val, s_no_throw_copies_ind);
  fix(it.m_p_e);
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
fix(entry_pointer p_e)
{
  size_type i = p_e - m_a_entries;
  if (i > 0 && entry_cmp::operator()(m_a_entries[parent(i)], m_a_entries[i]))
    {
      size_type parent_i = parent(i);
      while (i > 0
	     && entry_cmp::operator()(m_a_entries[parent_i], m_a_entries[i]))
	{
	  std::swap(m_a_entries[i], m_a_entries[parent_i]);
	  i = parent_i;
	  parent_i = parent(i);
	}

      PB_DS_ASSERT_VALID((*this))
      return;
    }

  while (i < m_size)
    {
      const size_type lchild_i = left_child(i);
      const size_type rchild_i = right_child(i);
      _GLIBCXX_DEBUG_ASSERT(rchild_i > lchild_i);

      const bool smaller_than_lchild = lchild_i < m_size &&
	entry_cmp::operator()(m_a_entries[i], m_a_entries[lchild_i]);

      const bool smaller_than_rchild = rchild_i < m_size &&
	entry_cmp::operator()(m_a_entries[i], m_a_entries[rchild_i]);

      const bool swap_with_rchild = smaller_than_rchild && (!smaller_than_lchild || entry_cmp::operator()(m_a_entries[lchild_i], m_a_entries[rchild_i]));

      const bool swap_with_lchild = !swap_with_rchild && smaller_than_lchild;

      if (swap_with_lchild)
	{
	  std::swap(m_a_entries[i], m_a_entries[lchild_i]);
	  i = lchild_i;
	}
      else if (swap_with_rchild)
	{
	  std::swap(m_a_entries[i], m_a_entries[rchild_i]);
	  i = rchild_i;
	}
      else
	i = m_size;
    }
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
swap_value_imp(entry_pointer p_e, value_type new_val, true_type)
{ *p_e = new_val; }

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
swap_value_imp(entry_pointer p_e, const_reference r_new_val, false_type)
{
  value_type tmp(r_new_val);
  (*p_e)->swap(tmp);
}
#endif
