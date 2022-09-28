// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file detail/binomial_heap_/constructors_destructor_fn_imps.hpp
 * Contains an implementation for binomial_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binomial_heap()
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binomial_heap(const Cmp_Fn& r_cmp_fn)
: base_type(r_cmp_fn)
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
binomial_heap(const PB_DS_CLASS_C_DEC& other)
: base_type(other)
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~binomial_heap() { }
#endif
