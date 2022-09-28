// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/entry_list_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s entry-list related functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
deallocate_links_in_list(entry_pointer p_e)
{
  while (p_e != 0)
    {
      entry_pointer p_dealloc_e = p_e;
      p_e = p_e->m_p_next;
      s_entry_allocator.deallocate(p_dealloc_e, 1);
    }
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::entry_pointer
PB_DS_CLASS_C_DEC::
get_entry(const_reference r_val, true_type)
{
  // Following line might throw an exception.
  entry_pointer p_e = s_entry_allocator.allocate(1);

  // Following lines* cannot* throw an exception.
  new (&p_e->m_value) value_type(r_val);
  return p_e;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::entry_pointer
PB_DS_CLASS_C_DEC::
get_entry(const_reference r_val, false_type)
{
  // Following line might throw an exception.
  entry_pointer p_e = s_entry_allocator.allocate(1);
  cond_dealtor_t cond(p_e);

  // Following lines might throw an exception.
  new (&p_e->m_value) value_type(r_val);
  cond.set_no_action();
  return p_e;
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
rels_entry(entry_pointer p_e)
{
  // The following lines cannot throw exceptions (unless if key-data dtors do).
  p_e->m_value.~value_type();
  s_entry_allocator.deallocate(p_e, 1);
}

#endif
