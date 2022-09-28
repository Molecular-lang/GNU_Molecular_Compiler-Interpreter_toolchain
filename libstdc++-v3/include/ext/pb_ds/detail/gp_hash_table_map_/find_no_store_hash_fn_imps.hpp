// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file gp_hash_table_map_/find_no_store_hash_fn_imps.hpp
 * Contains implementations of gp_ht_map_'s find related functions,
 * when the hash value is not stored.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::pointer
PB_DS_CLASS_C_DEC::
find_key_pointer(key_const_reference r_key, false_type)

