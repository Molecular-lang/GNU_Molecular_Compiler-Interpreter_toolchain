// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/iterator_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s iterators related functions, e.g.,
 * begin().
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::s_end_it;

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::s_const_end_it;

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
begin()
{
  pointer_ p_value;
  size_type pos;
  get_start_it_state(p_value, pos);
  return iterator(p_value, pos, this);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
end()
{ return s_end_it; }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin() const
{
  const_pointer_ p_value;
  size_type pos;
  get_start_it_state(p_value, pos);
  return const_iterator(p_value, pos, this);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end() const
{ return s_const_end_it; }

#endif
