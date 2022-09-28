// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file rc_binomial_heap_/split_join_fn_imps.hpp
 * Contains an implementation for rc_binomial_heap_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
template<typename Pred>
void
PB_DS_CLASS_C_DEC::
split(Pred pred, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  make_binomial_heap();
  other.make_binomial_heap();
  base_type::split(pred, other);
  base_type::find_max();
  other.find_max();

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
join(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  make_binomial_heap();
  other.make_binomial_heap();
  base_type::join(other);
  base_type::find_max();
  other.find_max();

  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

#endif
