// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file hash_exponential_size_policy_imp.hpp
 * Contains a resize size policy implementation.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
hash_exponential_size_policy(size_type start_size, size_type grow_factor) :
  m_start_size(start_size),
  m_grow_factor(grow_factor)
{ }

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{
  std::swap(m_start_size, other.m_start_size);
  std::swap(m_grow_factor, other.m_grow_factor);
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
get_nearest_larger_size(size_type size) const
{
  size_type ret = m_start_size;
  while (ret <= size)
    {
      const size_type next_ret = ret*  m_grow_factor;
      if (next_ret < ret)
	__throw_insert_error();
      ret = next_ret;
    }
  return ret;
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
get_nearest_smaller_size(size_type size) const
{
  size_type ret = m_start_size;
  while (true)
    {
      const size_type next_ret = ret*  m_grow_factor;
      if (next_ret < ret)
	__throw_resize_error();
      if (next_ret >= size)
	return (ret);
      ret = next_ret;
    }
  return ret;
}

#endif
