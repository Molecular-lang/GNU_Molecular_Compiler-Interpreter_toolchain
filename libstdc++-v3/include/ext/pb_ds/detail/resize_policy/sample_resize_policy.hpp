// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_resize_policy.hpp
 * Contains a sample resize policy for hash tables.
 */

#ifndef PB_DS_SAMPLE_RESIZE_POLICY_HPP
#define PB_DS_SAMPLE_RESIZE_POLICY_HPP

namespace __gnu_pbds
{
  /// A sample resize policy.
  class sample_resize_policy
  {
  public:
    /// Size type.
    typedef std::size_t size_type;

    /// Default constructor.
    sample_resize_policy();

    /// Copy constructor.
    sample_range_hashing(const sample_resize_policy& other);

    /// Swaps content.
    inline void
    swap(sample_resize_policy& other);

  protected:
    /// Notifies a search started.
    inline void
    notify_insert_search_start();

    /// Notifies a search encountered a collision.
    inline void
    notify_insert_search_collision();

    /// Notifies a search ended.
    inline void
    notify_insert_search_end();

    /// Notifies a search started.
    inline void
    notify_find_search_start();

    /// Notifies a search encountered a collision.
    inline void
    notify_find_search_collision();

    /// Notifies a search ended.
    inline void
    notify_find_search_end();

    /// Notifies a search started.
    inline void
    notify_erase_search_start();

    /// Notifies a search encountered a collision.
    inline void
    notify_erase_search_collision();

    /// Notifies a search ended.
    inline void
    notify_erase_search_end();

    /// Notifies an element was inserted.
    inline void
    notify_inserted(size_type num_e);

    /// Notifies an element was erased.
    inline void
    notify_erased(size_type num_e);

    /// Notifies the table was cleared.
    void
    notify_cleared();

    /// Notifies the table was resized to new_size.
    void
    notify_resized(size_type new_size);

    /// Queries whether a resize is needed.
    inline bool
    is_resize_needed() const;

    /// Queries what the new size should be.
    size_type
    get_new_size(size_type size, size_type num_used_e) const;
  };
}
#endif
