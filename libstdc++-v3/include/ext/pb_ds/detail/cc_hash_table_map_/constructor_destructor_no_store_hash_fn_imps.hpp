// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/constructor_destructor_no_store_hash_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s constructors, destructor,
 *    and related functions.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
constructor_insert_new_imp(mapped_const_reference r_val, size_type pos, 
			   false_type)
{
  // Following lines might throw an exception.
  entry_pointer p = get_entry(r_val, traits_base::s_no_throw_copies_indicator);

  // At this point no exceptions can be thrown.
  p->m_p_next = m_entries[pos];
  m_entries[pos] = p;
  _GLIBCXX_DEBUG_ONLY(debug_base::insert_new(r_key);)
}
#endif
