// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/debug_fn_imps.hpp
 * Contains implementations of cc_ht_map_'s debug-mode functions.
 */

#ifdef PB_DS_CLASS_C_DEC

#ifdef _GLIBCXX_DEBUG

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
assert_valid(const char* __file, int __line) const
{
  size_type calc_size = 0;
  for (const_iterator it = begin(); it != end(); ++it)
    {
      debug_base::check_key_exists(PB_DS_V2F(*it), __file, __line);
      ++calc_size;
    }
  debug_base::check_size(calc_size, __file, __line);
}

#endif 
#endif
