// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file hash_load_check_resize_trigger_size_base.hpp
 * Contains an base holding size for some resize policies.
 */

#ifndef PB_DS_HASH_LOAD_CHECK_RESIZE_TRIGGER_SIZE_BASE_HPP
#define PB_DS_HASH_LOAD_CHECK_RESIZE_TRIGGER_SIZE_BASE_HPP

namespace __gnu_pbds
{
  namespace detail
  {
    /// Primary template.
    template<typename Size_Type, bool Hold_Size>
    class hash_load_check_resize_trigger_size_base;

    /// Specializations.
    template<typename Size_Type>
    class hash_load_check_resize_trigger_size_base<Size_Type, true>
    {
    protected:
      typedef Size_Type size_type;

      hash_load_check_resize_trigger_size_base(): m_size(0)
      { }

      inline void
      swap(hash_load_check_resize_trigger_size_base& other)
      { std::swap(m_size, other.m_size); }

      inline void
      set_size(size_type size)
      { m_size = size; }

      inline size_type
      get_size() const
      { return m_size; }

    private:
      size_type m_size;
    };

    template<typename Size_Type>
    class hash_load_check_resize_trigger_size_base<Size_Type, false>
    {
    protected:
      typedef Size_Type size_type;

    protected:
      inline void
      swap(hash_load_check_resize_trigger_size_base& other) { }

      inline void
      set_size(size_type size) { }
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif
