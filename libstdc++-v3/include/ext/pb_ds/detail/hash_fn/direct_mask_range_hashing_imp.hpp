// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file direct_mask_range_hashing_imp.hpp
 * Contains a range-hashing policy implementation
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
swap(PB_DS_CLASS_C_DEC& other)
{ mask_based_base::swap(other); }

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
notify_resized(size_type size)
{ mask_based_base::notify_resized(size); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
operator()(size_type hash) const
{ return mask_based_base::range_hash(hash); }

#endif
