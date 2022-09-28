// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rc_binomial_heap_/erase_fn_imps.hpp
 * Contains an implementation for rc_binomial_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
pop()
{
  make_binomial_heap();
  _GLIBCXX_DEBUG_ASSERT(!base_type::empty());
  base_type::pop();
  base_type::find_max();
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
clear()
{
  base_type::clear();
  m_rc.clear();
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
make_binomial_heap()
{
  node_pointer p_nd = base_type::m_p_root;
  while (p_nd != 0)
    {
      node_pointer p_next = p_nd->m_p_next_sibling;
      if (p_next == 0)
	p_nd = p_next;
      else if (p_nd->m_metadata == p_next->m_metadata)
	p_nd = link_with_next_sibling(p_nd);
      else if (p_nd->m_metadata < p_next->m_metadata)
	p_nd = p_next;
#ifdef _GLIBCXX_DEBUG
      else
	_GLIBCXX_DEBUG_ASSERT(0);
#endif 
    }

  m_rc.clear();
}

PB_DS_CLASS_T_DEC
template<typename Pred>
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
erase_if(Pred pred)
{
  make_binomial_heap();
  const size_type ersd = base_type::erase_if(pred);
  base_type::find_max();
  PB_DS_ASSERT_VALID((*this))
  return ersd;
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
erase(point_iterator it)
{
  make_binomial_heap();
  base_type::erase(it);
  base_type::find_max();
}

#endif
