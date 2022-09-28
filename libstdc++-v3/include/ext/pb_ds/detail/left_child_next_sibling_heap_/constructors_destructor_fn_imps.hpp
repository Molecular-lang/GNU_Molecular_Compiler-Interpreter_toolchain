// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file left_child_next_sibling_heap_/constructors_destructor_fn_imps.hpp
 * Contains an implementation class for left_child_next_sibling_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::node_allocator
PB_DS_CLASS_C_DEC::s_node_allocator;

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::no_throw_copies_t
PB_DS_CLASS_C_DEC::s_no_throw_copies_ind;

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
left_child_next_sibling_heap() :
  m_p_root(0),
  m_size(0)
{
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
left_child_next_sibling_heap(const Cmp_Fn& r_cmp_fn) :
  Cmp_Fn(r_cmp_fn),
  m_p_root(0),
  m_size(0)
{
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
left_child_next_sibling_heap(const PB_DS_CLASS_C_DEC& other) 
: Cmp_Fn(other), m_p_root(0), m_size(0)
{
  m_size = other.m_size;
  PB_DS_ASSERT_VALID(other)
  m_p_root = recursive_copy_node(other.m_p_root);
  m_size = other.m_size;
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
  value_swap(other);
  std::swap((Cmp_Fn& )(*this), (Cmp_Fn& )other);
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
value_swap(PB_DS_CLASS_C_DEC& other)
{
  std::swap(m_p_root, other.m_p_root);
  std::swap(m_size, other.m_size);
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~left_child_next_sibling_heap()
{
  clear();
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::node_pointer
PB_DS_CLASS_C_DEC::
recursive_copy_node(node_const_pointer p_nd)
{
  if (p_nd == 0)
    return (0);

  node_pointer p_ret = s_node_allocator.allocate(1);

  __try
    {
      new (p_ret) node(*p_nd);
    }
  __catch(...)
    {
      s_node_allocator.deallocate(p_ret, 1);
      __throw_exception_again;
    }

  p_ret->m_p_l_child = p_ret->m_p_next_sibling =
    p_ret->m_p_prev_or_parent = 0;

  __try
    {
      p_ret->m_p_l_child = recursive_copy_node(p_nd->m_p_l_child);
      p_ret->m_p_next_sibling = recursive_copy_node(p_nd->m_p_next_sibling);
    }
  __catch(...)
    {
      clear_imp(p_ret);
      __throw_exception_again;
    }

  if (p_ret->m_p_l_child != 0)
    p_ret->m_p_l_child->m_p_prev_or_parent = p_ret;

  if (p_ret->m_p_next_sibling != 0)
    p_ret->m_p_next_sibling->m_p_prev_or_parent =
      p_nd->m_p_next_sibling->m_p_prev_or_parent == p_nd ? p_ret : 0;

  return p_ret;
}

#endif
