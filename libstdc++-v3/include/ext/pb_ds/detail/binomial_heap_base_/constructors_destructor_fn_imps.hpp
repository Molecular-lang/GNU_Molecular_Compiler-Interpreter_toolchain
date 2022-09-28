// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file binomial_heap_base_/constructors_destructor_fn_imps.hpp
 * Contains an implementation class for a base of binomial heaps.
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
  PB_DS_ASSERT_VALID_COND((*this),false)
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binomial_heap_base() : m_p_max(0)
{
  PB_DS_ASSERT_VALID_COND((*this),false)
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binomial_heap_base(const Cmp_Fn& r_cmp_fn)
: base_type(r_cmp_fn), m_p_max(0)
{ PB_DS_ASSERT_VALID_COND((*this),false) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binomial_heap_base(const PB_DS_CLASS_C_DEC& other)
: base_type(other), m_p_max(0)
{ PB_DS_ASSERT_VALID_COND((*this),false) }

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID_COND((*this),false)
  base_type::swap(other);
  std::swap(m_p_max, other.m_p_max);
  PB_DS_ASSERT_VALID_COND((*this),false)
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~binomial_heap_base()
{ }
#endif
