// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file thin_heap_/constructors_destructor_fn_imps.hpp
 * Contains an implementation for thin_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
template<typename It>
void
PB_DS_CLASS_C_DEC::
copy_from_range(It first_it, It last_it)
{
  while (first_it != last_it)
    push(*(first_it++));
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
thin_heap() : m_p_max(0)
{
  initialize();
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
thin_heap(const Cmp_Fn& r_cmp_fn) 
: base_type(r_cmp_fn), m_p_max(0)
{
  initialize();
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
thin_heap(const PB_DS_CLASS_C_DEC& other) 
: base_type(other)
{
  initialize();
  m_p_max = base_type::m_p_root;
  for (node_pointer p_nd = base_type::m_p_root; p_nd != 0; 
       p_nd = p_nd->m_p_next_sibling)
    if (Cmp_Fn::operator()(m_p_max->m_value, p_nd->m_value))
      m_p_max = p_nd;

  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  base_type::swap(other);
  std::swap(m_p_max, other.m_p_max);
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~thin_heap()
{ }

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
initialize()
{ std::fill(m_a_aux, m_a_aux + max_rank, static_cast<node_pointer>(0)); }

#endif
