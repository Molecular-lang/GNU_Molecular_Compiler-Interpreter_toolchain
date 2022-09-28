// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file thin_heap_/trace_fn_imps.hpp
 * Contains an implementation class for left_child_next_sibling_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_THIN_HEAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  std::cerr << std::endl;
  std::cerr << "m_p_max " << m_p_max << std::endl;
  base_type::trace();
}

#endif // #ifdef PB_DS_THIN_HEAP_TRACE_
#endif
