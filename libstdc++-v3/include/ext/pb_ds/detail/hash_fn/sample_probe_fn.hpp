// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_probe_fn.hpp
 * Contains a sample probe policy.
 */

#ifndef PB_DS_SAMPLE_PROBE_FN_HPP
#define PB_DS_SAMPLE_PROBE_FN_HPP

namespace __gnu_pbds
{
  /// A sample probe policy.
  class sample_probe_fn
  {
  public:
    typedef std::size_t size_type;

    /// Default constructor.
    sample_probe_fn();

    /// Copy constructor.
    sample_probe_fn(const sample_probe_fn&);

    /// Swaps content.
    inline void
    swap(sample_probe_fn&);

  protected:
    /// Returns the i-th offset from the hash value of some key r_key.
    inline size_type
    operator()(key_const_reference r_key, size_type i) const;
  };
}
#endif // #ifndef PB_DS_SAMPLE_PROBE_FN_HPP
