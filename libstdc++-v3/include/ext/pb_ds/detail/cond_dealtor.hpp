// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_COND_DEALTOR_HPP
#define PB_DS_COND_DEALTOR_HPP

#include <ext/pb_ds/detail/types_traits.hpp>

namespace __gnu_pbds
{
  namespace detail
  {
    /// Conditional deallocate constructor argument.
    template<typename Entry, typename _Alloc>
      class cond_dealtor
      {
	typedef rebind_traits<_Alloc, Entry>	alloc_traits;

      public:
	typedef typename alloc_traits::allocator_type entry_allocator;
	typedef typename alloc_traits::pointer	      entry_pointer;

	cond_dealtor(entry_pointer p_e)
	: m_p_e(p_e), m_no_action_destructor(false) { }

	~cond_dealtor()
	{
	  if (m_no_action_destructor)
	    return;
	  s_alloc.deallocate(m_p_e, 1);
	}

	void
	set_no_action()
	{ m_no_action_destructor = true; }

      private:
	entry_pointer 		m_p_e;
	bool 			m_no_action_destructor;
	static entry_allocator 	s_alloc;
      };

    template<typename Entry, class _Alloc>
      typename cond_dealtor<Entry, _Alloc>::entry_allocator
      cond_dealtor<Entry, _Alloc>::s_alloc;
  } // namespace detail
} // namespace __gnu_pbds

#endif // #ifndef PB_DS_COND_DEALTOR_HPP
