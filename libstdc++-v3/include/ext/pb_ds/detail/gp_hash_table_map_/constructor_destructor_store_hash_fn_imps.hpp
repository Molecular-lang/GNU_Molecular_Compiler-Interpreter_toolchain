// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/constructor_destructor_store_hash_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s constructors, destructor,
 * and related functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
constructor_insert_new_imp(mapped_const_reference r_val, size_type pos, 
			   true_type)
{
  _GLIBCXX_DEBUG_ASSERT(m_entries[pos].m_stat != valid_entry_status);
  entry* const p_e = m_entries + pos;
  new (&p_e->m_value) mapped_value_type(r_val);
  p_e->m_hash = ranged_probe_fn_base::operator()(PB_DS_V2F(r_val)).second;
  p_e->m_stat = valid_entry_status;
  _GLIBCXX_DEBUG_ONLY(debug_base::insert_new(p_e->m_value.first);)
}
#endif
