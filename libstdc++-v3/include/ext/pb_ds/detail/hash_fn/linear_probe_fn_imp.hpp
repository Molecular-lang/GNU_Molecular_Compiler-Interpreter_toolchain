// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file linear_probe_fn_imp.hpp
 * Contains a probe policy implementation
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{ }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
operator()(size_type i) const
{
  return (i);
}
#endif
