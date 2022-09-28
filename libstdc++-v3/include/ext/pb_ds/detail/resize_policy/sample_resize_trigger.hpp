// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_resize_trigger.hpp
 * Contains a sample resize trigger policy class.
 */

#ifndef PB_DS_SAMPLE_RESIZE_TRIGGER_HPP
#define PB_DS_SAMPLE_RESIZE_TRIGGER_HPP

namespace __gnu_pbds
{
  /// A sample resize trigger policy.
  class sample_resize_trigger
  {
  public:
    /// Size type.
    typedef std::size_t size_type;

    /// Default constructor.
    sample_resize_trigger();

    /// Copy constructor.
    sample_range_hashing(const sample_resize_trigger&);

    /// Swaps content.
    inline void
    swap(sample_resize_trigger&);

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

    /// Notifies an element was inserted. the total number of entries in
    /// the table is num_entries.
    inline void
    notify_inserted(size_type num_entries);

    /// Notifies an element was erased.
    inline void
    notify_erased(size_type num_entries);

    /// Notifies the table was cleared.
    void
    notify_cleared();

    /// Notifies the table was resized as a result of this object's
    /// signifying that a resize is needed.
    void
    notify_resized(size_type new_size);

    /// Notifies the table was resized externally.
    void
    notify_externally_resized(size_type new_size);

    /// Queries whether a resize is needed.
    inline bool
    is_resize_needed() const;

    /// Queries whether a grow is needed.
    inline bool
    is_grow_needed(size_type size, size_type num_entries) const;

  private:
    /// Resizes to new_size.
    virtual void
    do_resize(size_type);
  };
}
#endif
