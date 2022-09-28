// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rc_binomial_heap_/constructors_destructor_fn_imps.hpp
 * Contains an implementation for rc_binomial_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
rc_binomial_heap()
{
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
rc_binomial_heap(const Cmp_Fn& r_cmp_fn) 
: base_type(r_cmp_fn)
{
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
rc_binomial_heap(const PB_DS_CLASS_C_DEC& other) 
: base_type(other)
{
  make_binomial_heap();
  base_type::find_max();
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~rc_binomial_heap()
{ }

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  base_type::swap(other);
  m_rc.swap(other.m_rc);

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}
#endif
