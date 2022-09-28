// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file lu_counter_metadata.hpp
 * Contains implementation of a lu counter policy's metadata.
 */

namespace __gnu_pbds
{
  namespace detail
  {
    template<typename Size_Type>
      class lu_counter_policy_base;

    /// A list-update metadata type that moves elements to the front of
    /// the list based on the counter algorithm.
    template<typename Size_Type = std::size_t>
      class lu_counter_metadata
      {
      public:
	typedef Size_Type 	size_type;

      private:
	lu_counter_metadata(size_type init_count) : m_count(init_count)
	{ }

	friend class lu_counter_policy_base<size_type>;

	mutable size_type 	m_count;
    };

    /// Base class for list-update counter policy.
    template<typename Size_Type>
      class lu_counter_policy_base
      {
      protected:
	typedef Size_Type 	size_type;

	lu_counter_metadata<size_type>
	operator()(size_type max_size) const
	{ return lu_counter_metadata<Size_Type>(std::rand() % max_size); }

	template<typename Metadata_Reference>
	bool
	operator()(Metadata_Reference r_data, size_type m_max_count) const
	{
	  if (++r_data.m_count != m_max_count)
	    return false;
	  r_data.m_count = 0;
	  return true;
	}
      };
  } // namespace detail
} // namespace __gnu_pbds
