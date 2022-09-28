// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_size_policy.hpp
 * Contains a sample size resize-policy.
 */

#ifndef PB_DS_SAMPLE_SIZE_POLICY_HPP
#define PB_DS_SAMPLE_SIZE_POLICY_HPP

namespace __gnu_pbds
{
  /// A sample size policy.
  class sample_size_policy
  {
  public:
    /// Size type.
    typedef std::size_t size_type;

    /// Default constructor.
    sample_size_policy();

    /// Copy constructor.
    sample_range_hashing(const sample_size_policy&);

    /// Swaps content.
    inline void
    swap(sample_size_policy& other);

  protected:
    /// Given a __size size, returns a __size that is larger.
    inline size_type
    get_nearest_larger_size(size_type size) const;

    /// Given a __size size, returns a __size that is smaller.
    inline size_type
    get_nearest_smaller_size(size_type size) const;
  };
}
#endif
