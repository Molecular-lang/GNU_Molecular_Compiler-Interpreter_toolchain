// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file ov_tree_map_/insert_fn_imps.hpp
 * Contains an implementation class for ov_tree_.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
void
PB_DS_CLASS_C_DEC::
reallocate_metadata(null_node_update_pointer, size_type)
{ }

PB_DS_CLASS_T_DEC
template<typename Node_Update_>
void
PB_DS_CLASS_C_DEC::
reallocate_metadata(Node_Update_* , size_type new_size)
{
  metadata_pointer a_new_metadata_vec =(new_size == 0) ? 0 : s_metadata_alloc.allocate(new_size);

  if (m_a_metadata != 0)
    {
      for (size_type i = 0; i < m_size; ++i)
	m_a_metadata[i].~metadata_type();
      s_metadata_alloc.deallocate(m_a_metadata, m_size);
    }
  std::swap(m_a_metadata, a_new_metadata_vec);
}

#endif
