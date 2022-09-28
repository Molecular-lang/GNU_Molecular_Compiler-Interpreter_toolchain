// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file list_update_map_/entry_metadata_base.hpp
 * Contains an implementation for a list update map.
 */

#ifndef PB_DS_LU_MAP_ENTRY_METADATA_BASE_HPP
#define PB_DS_LU_MAP_ENTRY_METADATA_BASE_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    template<typename Metadata>
    struct lu_map_entry_metadata_base
    {
      Metadata m_update_metadata;
    };
    
    template<>
    struct lu_map_entry_metadata_base<null_type>
    { };  
  } // namespace detail
} // namespace __gnu_pbds

#endif 
