// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file sample_update_policy.hpp
 * Contains a sample policy for list update containers.
 */

#ifndef PB_DS_SAMPLE_UPDATE_POLICY_HPP
#define PB_DS_SAMPLE_UPDATE_POLICY_HPP

namespace __gnu_pbds
{
  /// A sample list-update policy.
  struct sample_update_policy
  {
    /// Default constructor.
    sample_update_policy();

    /// Copy constructor.
    sample_update_policy(const sample_update_policy&);

    /// Swaps content.
    inline void
    swap(sample_update_policy& other);

  protected:
    /// Metadata on which this functor operates.
    typedef some_metadata_type metadata_type;

    /// Creates a metadata object.
    metadata_type
    operator()() const;

    /// Decides whether a metadata object should be moved to the front
    /// of the list. A list-update based containers object will call
    /// this method to decide whether to move a node to the front of
    /// the list. The method shoule return true if the node should be
    /// moved to the front of the list.
    bool
    operator()(metadata_reference) const;
  };
}
#endif
