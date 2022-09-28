// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_ranged_probe_fn.hpp
 * Contains a ranged probe policy.
 */

#ifndef PB_DS_SAMPLE_RANGED_PROBE_FN_HPP
#define PB_DS_SAMPLE_RANGED_PROBE_FN_HPP

namespace __gnu_pbds
{
  /// A sample ranged-probe functor.
  class sample_ranged_probe_fn
  {
  public:
    typedef std::size_t 	size_type;

    // Default constructor.
    sample_ranged_probe_fn();

    // Copy constructor.
    sample_ranged_probe_fn(const sample_ranged_probe_fn&);

    // Swaps content.
    inline void
    swap(sample_ranged_probe_fn&);

  protected:

    // Notifies the policy object that the container's __size has
    // changed to size.
    void
    notify_resized(size_type);

    // Transforms the const key reference r_key into the i-th position
    // within the table. This method is called for each collision within
    // the probe sequence.
    inline size_type
    operator()(key_const_reference, std::size_t, size_type) const;

  };
}
#endif // #ifndef PB_DS_SAMPLE_RANGED_PROBE_FN_HPP
