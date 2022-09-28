// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_ranged_hash_fn.hpp
 * Contains a ranged hash policy.
 */

#ifndef PB_DS_SAMPLE_RANGED_HASH_FN_HPP
#define PB_DS_SAMPLE_RANGED_HASH_FN_HPP

namespace __gnu_pbds
{
  /// A sample ranged-hash functor.
  class sample_ranged_hash_fn
  {
  public:
    typedef std::size_t size_type;

    /// Default constructor.
    sample_ranged_hash_fn();

    /// Copy constructor.
    sample_ranged_hash_fn(const sample_ranged_hash_fn&);

    /// Swaps content.
    inline void
    swap(sample_ranged_hash_fn&);

  protected:

    /// Notifies the policy object that the container's __size has
    /// changed to size.
    void
    notify_resized(size_type);

    /// Transforms key_const_reference into a position within the table.
    inline size_type
    operator()(key_const_reference) const;

  };
}
#endif // #ifndef PB_DS_SAMPLE_RANGED_HASH_FN_HPP
