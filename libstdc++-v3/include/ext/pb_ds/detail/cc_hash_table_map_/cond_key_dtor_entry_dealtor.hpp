// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file cc_hash_table_map_/cond_key_dtor_entry_dealtor.hpp
 * Contains a conditional key destructor, used for exception handling.
 */

namespace __gnu_pbds
{
  namespace detail
  {
    /// Conditional dey destructor, cc_hash.
    template<typename HT_Map>
    class cond_dealtor
    {
    public:
      typedef typename HT_Map::entry 		entry;
      typedef typename HT_Map::entry_allocator 	entry_allocator;
      typedef typename HT_Map::key_type 	key_type;

      cond_dealtor(entry_allocator* p_a, entry* p_e)
      : m_p_a(p_a), m_p_e(p_e), m_key_destruct(false),
	m_no_action_destructor(false)
      { }

      inline
      ~cond_dealtor();

      void
      set_key_destruct()
      { m_key_destruct = true; }

      void
      set_no_action_destructor()
      { m_no_action_destructor = true; }

    protected:
      entry_allocator* const 			m_p_a;
      entry* const 				m_p_e;

      bool 					m_key_destruct;
      bool 					m_no_action_destructor;
    };

    template<typename HT_Map>
    inline
    cond_dealtor<HT_Map>::
    ~cond_dealtor()
    {
      if (m_no_action_destructor)
	return;
      if (m_key_destruct)
	m_p_e->m_value.first.~key_type();
      m_p_a->deallocate(m_p_e, 1);
    }
  } // namespace detail
} // namespace __gnu_pbds
