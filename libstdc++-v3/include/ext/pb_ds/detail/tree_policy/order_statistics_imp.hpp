// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file tree_policy/order_statistics_imp.hpp
 * Contains forward declarations for order_statistics_key
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::iterator
PB_DS_CLASS_C_DEC::
find_by_order(size_type order)
{
  node_iterator it = node_begin();
  node_iterator end_it = node_end();

  while (it != end_it)
    {
      node_iterator l_it = it.get_l_child();
      const size_type o = (l_it == end_it)? 0 : l_it.get_metadata();

      if (order == o)
	return *it;
      else if (order < o)
	it = l_it;
      else
        {
	  order -= o + 1;
	  it = it.get_r_child();
        }
    }

  return base_type::end_iterator();
}

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::const_iterator
PB_DS_CLASS_C_DEC::
find_by_order(size_type order) const
{ return const_cast<PB_DS_CLASS_C_DEC*>(this)->find_by_order(order); }

PB_DS_CLASS_T_DEC
inline typename PB_DS_CLASS_C_DEC::size_type
PB_DS_CLASS_C_DEC::
order_of_key(key_const_reference r_key) const
{
  node_const_iterator it = node_begin();
  node_const_iterator end_it = node_end();

  const cmp_fn& r_cmp_fn = const_cast<PB_DS_CLASS_C_DEC*>(this)->get_cmp_fn();
  size_type ord = 0;
  while (it != end_it)
    {
      node_const_iterator l_it = it.get_l_child();

      if (r_cmp_fn(r_key, this->extract_key(*(*it))))
	it = l_it;
      else if (r_cmp_fn(this->extract_key(*(*it)), r_key))
        {
	  ord += (l_it == end_it)? 1 : 1 + l_it.get_metadata();
	  it = it.get_r_child();
        }
      else
        {
	  ord += (l_it == end_it)? 0 : l_it.get_metadata();
	  it = end_it;
        }
    }
  return ord;
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
operator()(node_iterator node_it, node_const_iterator end_nd_it) const
{
  node_iterator l_it = node_it.get_l_child();
  const size_type l_rank = (l_it == end_nd_it) ? 0 : l_it.get_metadata();

  node_iterator r_it = node_it.get_r_child();
  const size_type r_rank = (r_it == end_nd_it) ? 0 : r_it.get_metadata();

  const_cast<metadata_reference>(node_it.get_metadata())= 1 + l_rank + r_rank;
}

PB_DS_CLASS_T_DEC
PB_DS_CLASS_C_DEC::
~tree_order_statistics_node_update()
{ }
#endif
