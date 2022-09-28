// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_range_hashing.hpp
 * Contains a range hashing policy.
 */

#ifndef PB_DS_SAMPLE_RANGE_HASHING_HPP
#define PB_DS_SAMPLE_RANGE_HASHING_HPP

namespace __gnu_pbds
{
  /// A sample range-hashing functor.
  class sample_range_hashing
  {
  public:
    /// Size type.
    typedef std::size_t size_type;

    /// Default constructor.
    sample_range_hashing();

    /// Copy constructor.
    sample_range_hashing(const sample_range_hashing& other);

    /// Swaps content.
    inline void
    swap(sample_range_hashing& other);

  protected:
    /// Notifies the policy object that the container's size has
    /// changed to argument's size.
    void
    notify_resized(size_type);

    /// Transforms the __hash value hash into a ranged-hash value.
    inline size_type
    operator()(size_type ) const;
  };
}
#endif // #ifndef PB_DS_SAMPLE_RANGE_HASHING_HPP
