// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file mod_based_range_hashing.hpp
 * Contains a range hashing policy base.
 */

#ifndef PB_DS_MOD_BASED_RANGE_HASHING_HPP
#define PB_DS_MOD_BASED_RANGE_HASHING_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    /// Mod based range hashing.
    template<typename Size_Type>
    class mod_based_range_hashing
    {
    protected:
      typedef Size_Type 	size_type;

      void
      swap(mod_based_range_hashing& other)
      { std::swap(m_size, other.m_size); }

      void
      notify_resized(size_type s)
      { m_size = s; }

      inline size_type
      range_hash(size_type s) const
      { return s % m_size; }

    private:
      size_type m_size;
    };
  } // namespace detail

} // namespace __gnu_pbds

#endif // #ifndef PB_DS_MOD_BASED_RANGE_HASHING_HPP
