// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/insert_fn_imps.hpp
 * Contains implementations of lu_map_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline std::pair<
  typename PB_DS_CLASS_C_DEC::point_iterator,
  bool>
PB_DS_CLASS_C_DEC::
insert(const_reference r_val)
{
  PB_DS_ASSERT_VALID((*this))
  entry_pointer p_l = find_imp(PB_DS_V2F(r_val));

  if (p_l != 0)
    {
      PB_DS_CHECK_KEY_EXISTS(PB_DS_V2F(r_val))
      return std::make_pair(point_iterator(&p_l->m_value), false);
    }

  PB_DS_CHECK_KEY_DOES_NOT_EXIST(PB_DS_V2F(r_val))

  p_l = allocate_new_entry(r_val, traits_base::m_no_throw_copies_indicator);
  p_l->m_p_next = m_p_l;
  m_p_l = p_l;
  PB_DS_ASSERT_VALID((*this))
  return std::make_pair(point_iterator(&p_l->m_value), true);
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::entry_pointer
PB_DS_CLASS_C_DEC::
allocate_new_entry(const_reference r_val, false_type)
{
  entry_pointer p_l = s_entry_allocator.allocate(1);
  cond_dealtor_t cond(p_l);
  new (const_cast<void* >(static_cast<const void* >(&p_l->m_value)))
    value_type(r_val);

  cond.set_no_action();
  _GLIBCXX_DEBUG_ONLY(debug_base::insert_new(PB_DS_V2F(r_val));)
  init_entry_metadata(p_l, s_metadata_type_indicator);
  return p_l;
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::entry_pointer
PB_DS_CLASS_C_DEC::
allocate_new_entry(const_reference    r_val, true_type)
{
  entry_pointer p_l = s_entry_allocator.allocate(1);
  new (&p_l->m_value) value_type(r_val);
  _GLIBCXX_DEBUG_ONLY(debug_base::insert_new(PB_DS_V2F(r_val));)
  init_entry_metadata(p_l, s_metadata_type_indicator);
  return p_l;
}

PB_DS_CLASS_T_DEC
template<typename Metadata>
inline void
PB_DS_CLASS_C_DEC::
init_entry_metadata(entry_pointer p_l, type_to_type<Metadata>)
{ new (&p_l->m_update_metadata) Metadata(s_update_policy()); }

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
init_entry_metadata(entry_pointer, type_to_type<null_type>)
{ }

#endif
