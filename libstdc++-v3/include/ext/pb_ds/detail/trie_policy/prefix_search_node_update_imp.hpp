// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file trie_policy/prefix_search_node_update_imp.hpp
 * Contains an implementation of prefix_search_node_update.
 */

#ifdef PB_DS_CLASS_C_DEC

PB_DS_CLASS_T_DEC
std::pair<
  typename PB_DS_CLASS_C_DEC::const_iterator,
  typename PB_DS_CLASS_C_DEC::const_iterator>
PB_DS_CLASS_C_DEC::
prefix_range(key_const_reference r_key) const
{
  const access_traits& r_traits = get_access_traits();
  return (prefix_range(r_traits.begin(r_key), r_traits.end(r_key)));
}

PB_DS_CLASS_T_DEC
std::pair<
  typename PB_DS_CLASS_C_DEC::iterator,
  typename PB_DS_CLASS_C_DEC::iterator>
PB_DS_CLASS_C_DEC::
prefix_range(key_const_reference r_key)
{
  return (prefix_range(get_access_traits().begin(r_key),
		       get_access_traits().end(r_key)));
}

PB_DS_CLASS_T_DEC
std::pair<
  typename PB_DS_CLASS_C_DEC::const_iterator,
  typename PB_DS_CLASS_C_DEC::const_iterator>
PB_DS_CLASS_C_DEC::
prefix_range(typename access_traits::const_iterator b,
	     typename access_traits::const_iterator e) const
{
  const std::pair<iterator, iterator> non_const_ret =
    const_cast<PB_DS_CLASS_C_DEC* >(this)->prefix_range(b, e);

  return (std::make_pair(const_iterator(non_const_ret.first),
			 const_iterator(non_const_ret.second)));
}

PB_DS_CLASS_T_DEC
std::pair<
  typename PB_DS_CLASS_C_DEC::iterator,
  typename PB_DS_CLASS_C_DEC::iterator>
PB_DS_CLASS_C_DEC::
prefix_range(typename access_traits::const_iterator b,
	     typename access_traits::const_iterator e)
{
  Node_Itr nd_it = node_begin();
  Node_Itr end_nd_it = node_end();

  const access_traits& r_traits = get_access_traits();
  const size_type given_range_length = std::distance(b, e);

  while (true)
    {
      if (nd_it == end_nd_it)
	return (std::make_pair(end(), end()));

      const size_type common_range_length =
	base_type::common_prefix_len(nd_it, b, e, r_traits);

      if (common_range_length >= given_range_length)
	{
	  iterator ret_b = this->leftmost_it(nd_it);
	  iterator ret_e = this->rightmost_it(nd_it);
	  return (std::make_pair(ret_b, ++ret_e));
	}
      nd_it = next_child(nd_it, b, e, end_nd_it, r_traits);
    }
}

PB_DS_CLASS_T_DEC
typename PB_DS_CLASS_C_DEC::node_iterator
PB_DS_CLASS_C_DEC::
next_child(node_iterator nd_it, typename access_traits::const_iterator b,
	   typename access_traits::const_iterator e, node_iterator end_nd_it,
	   const access_traits& r_traits)
{
  const size_type num_children = nd_it.num_children();
  node_iterator ret = end_nd_it;
  size_type max_length = 0;
  for (size_type i = 0; i < num_children; ++i)
    {
      node_iterator pot = nd_it.get_child(i);
      const size_type common_range_length =
	base_type::common_prefix_len(pot, b, e, r_traits);

      if (common_range_length > max_length)
	{
	  ret = pot;
	  max_length = common_range_length;
	}
    }
  return (ret);
}

PB_DS_CLASS_T_DEC
inline void
PB_DS_CLASS_C_DEC::
operator()(node_iterator /*nd_it*/, node_const_iterator /*end_nd_it*/) const
{ }
#endif
