// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rc_binomial_heap_/trace_fn_imps.hpp
 * Contains an implementation for rc_binomial_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef PB_DS_RC_BINOMIAL_HEAP_TRACE_

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
trace() const
{
  base_type::trace();
  m_rc.trace();
}

#endif // #ifdef PB_DS_RC_BINOMIAL_HEAP_TRACE_
#endif
