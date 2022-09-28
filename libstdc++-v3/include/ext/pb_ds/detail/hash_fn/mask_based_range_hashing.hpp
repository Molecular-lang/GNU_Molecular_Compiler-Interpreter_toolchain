// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file mask_based_range_hashing.hpp
 * Contains a range hashing policy base.
 */

#ifndef PB_DS_MASK_BASED_RANGE_HASHING_HPP
#define PB_DS_MASK_BASED_RANGE_HASHING_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    /// Range hashing policy.
    template<typename Size_Type>
    class mask_based_range_hashing
    {
    protected:
      typedef Size_Type 	size_type;

      void
      swap(mask_based_range_hashing& other)
      { std::swap(m_mask, other.m_mask); }

      void
      notify_resized(size_type size);

      inline size_type
      range_hash(size_type hash) const
      { return size_type(hash & m_mask); }

    private:
      size_type 		m_mask;
      const static size_type 	s_num_bits_in_size_type;
      const static size_type 	s_highest_bit_1;
    };

    template<typename Size_Type>
    const typename mask_based_range_hashing<Size_Type>::size_type
    mask_based_range_hashing<Size_Type>::s_num_bits_in_size_type =
      sizeof(typename mask_based_range_hashing<Size_Type>::size_type) << 3;

    template<typename Size_Type>
    const typename mask_based_range_hashing<Size_Type>::size_type mask_based_range_hashing<Size_Type>::s_highest_bit_1 = static_cast<typename mask_based_range_hashing<Size_Type>::size_type>(1) << (s_num_bits_in_size_type - 1);

 
    template<typename Size_Type>
    void
    mask_based_range_hashing<Size_Type>::
    notify_resized(size_type size)
    {
      size_type i = 0;
      while (size ^ s_highest_bit_1)
	{
	  size <<= 1;
	  ++i;
	}

      m_mask = 1;
      i += 2;
      while (i++ < s_num_bits_in_size_type)
        m_mask = (m_mask << 1) ^ 1;
    }
  } // namespace detail
} // namespace __gnu_pbds

#endif
