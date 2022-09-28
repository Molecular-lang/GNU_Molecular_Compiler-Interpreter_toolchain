// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/split_join_fn_imps.hpp
 * Contains an implementation class for ov_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
split(key_const_reference r_key, PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)

  if (m_size == 0)
    {
      other.clear();
      return;
    }

  if (Cmp_Fn::operator()(r_key, PB_DS_V2F(*begin())))
    {
      value_swap(other);
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return;
    }

  if (!Cmp_Fn::operator()(r_key, PB_DS_V2F(*(end() - 1))))
    {
      return;
    }

  if (m_size == 1)
    {
      value_swap(other);
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return;
    }

  iterator it = upper_bound(r_key);
  PB_DS_CLASS_C_DEC new_other(other, other);
  new_other.copy_from_ordered_range(it, end());
  PB_DS_CLASS_C_DEC new_this(*this, *this);
  new_this.copy_from_ordered_range(begin(), it);

  // No exceptions from this point.
  other.update(other.node_begin(), (node_update*)(&other));
  update(node_begin(), (node_update*)this);
  other.value_swap(new_other);
  value_swap(new_this);
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
join(PB_DS_CLASS_C_DEC& other)
{
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
  if (other.m_size == 0)
    return;

  if (m_size == 0)
    {
      value_swap(other);
      PB_DS_ASSERT_VALID((*this))
      PB_DS_ASSERT_VALID(other)
      return;
    }

  const bool greater = Cmp_Fn::operator()(PB_DS_V2F(*(end() - 1)),
					  PB_DS_V2F(*other.begin()));

  const bool lesser = Cmp_Fn::operator()(PB_DS_V2F(*(other.end() - 1)),
					 PB_DS_V2F(*begin()));

  if (!greater && !lesser)
    __throw_join_error();

  PB_DS_CLASS_C_DEC new_this(*this, *this);

  if (greater)
    new_this.copy_from_ordered_range(begin(), end(),
				     other.begin(), other.end());
  else
    new_this.copy_from_ordered_range(other.begin(), other.end(),
				     begin(), end());

  // No exceptions from this point.
  value_swap(new_this);
  other.clear();
  PB_DS_ASSERT_VALID((*this))
  PB_DS_ASSERT_VALID(other)
}
#endif
