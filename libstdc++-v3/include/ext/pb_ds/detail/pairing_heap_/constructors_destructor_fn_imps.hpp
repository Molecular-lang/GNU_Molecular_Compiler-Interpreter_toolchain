// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file pairing_heap_/constructors_destructor_fn_imps.hpp
 * Contains an implementation class for a pairing heap.
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
pairing_heap()
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
pairing_heap(const Cmp_Fn& r_cmp_fn)
: base_type(r_cmp_fn)
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
pairing_heap(const PB_DS_CLASS_C_DEC& other)
: base_type(other)
{ PB_DS_ASSERT_VALID((*this)) }

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  base_type::swap(other);
  PB_DS_ASSERT_VALID((*this))
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~pairing_heap()
{ }
#endif
