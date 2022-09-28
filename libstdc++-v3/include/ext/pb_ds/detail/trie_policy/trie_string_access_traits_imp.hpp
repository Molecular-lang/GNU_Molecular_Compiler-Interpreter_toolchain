// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file trie_policy/trie_string_access_traits_imp.hpp
 * Contains a policy for extracting character positions from
 *    a string for a vector-based PATRICIA tree
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
detail::integral_constant<int, Reverse> PB_DS_CLASS_C_DEC::s_rev_ind;

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
e_pos(e_type e)
{
  return (static_cast<size_type>(e - min_e_val));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin(key_const_reference r_key)
{
  return (begin_imp(r_key, s_rev_ind));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end(key_const_reference r_key)
{
  return (end_imp(r_key, s_rev_ind));
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin_imp(key_const_reference r_key, detail::false_type)
{
  return (r_key.begin());
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
begin_imp(key_const_reference r_key, detail::true_type)
{
  return (r_key.rbegin());
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end_imp(key_const_reference r_key, detail::false_type)
{
  return (r_key.end());
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
end_imp(key_const_reference r_key, detail::true_type)
{
  return (r_key.rend());
}
#endif
