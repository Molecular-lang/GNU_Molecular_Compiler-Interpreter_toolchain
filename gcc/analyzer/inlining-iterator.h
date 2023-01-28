/* Iterator for walking a chain of inlining locations.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_INLINING_ITERATOR_H
#define GCC_ANALYZER_INLINING_ITERATOR_H

/* Iterator for walking a chain of inlining locations.

   The fndecls and locations will be traversed from innermost to outermost.
   For example, given:

    inline void inner (void)
    {
       ...LOCATION HERE...
    }
    void outer (void)
    {
       inner (); <-- CALLSITE
    }

   then the fndecl will be "inner" on the initial iteration, and "outer" on
   the second (final) iteration.

   Compare with lhd_print_error_function, cp_print_error_function,
   and optrecord_json_writer::inlining_chain_to_json.  */

class inlining_iterator
{
public:
  inlining_iterator (location_t loc)
  : m_abstract_origin (LOCATION_BLOCK (loc)),
    m_callsite (UNKNOWN_LOCATION), m_fndecl (NULL),
    m_next_abstract_origin (NULL)
  {
    prepare_iteration ();
  }

  bool done_p () const { return m_abstract_origin == NULL; }

  void next ()
  {
    m_abstract_origin = m_next_abstract_origin;
    prepare_iteration ();
  }

  tree get_fndecl () const { return m_fndecl; }
  location_t get_callsite () const { return m_callsite; }
  tree get_block () const { return m_abstract_origin; }

private:
  void prepare_iteration ()
  {
    if (done_p ())
      return;
    tree block = m_abstract_origin;
    m_callsite = BLOCK_SOURCE_LOCATION (block);
    m_fndecl = NULL;
    block = BLOCK_SUPERCONTEXT (block);
    while (block && TREE_CODE (block) == BLOCK
	   && BLOCK_ABSTRACT_ORIGIN (block))
      {
	tree ao = BLOCK_ABSTRACT_ORIGIN (block);
	if (TREE_CODE (ao) == FUNCTION_DECL)
	  {
	    m_fndecl = ao;
	    break;
	  }
	else if (TREE_CODE (ao) != BLOCK)
	  break;

	block = BLOCK_SUPERCONTEXT (block);
      }
    if (m_fndecl)
      m_next_abstract_origin = block;
    else
      {
	while (block && TREE_CODE (block) == BLOCK)
	  block = BLOCK_SUPERCONTEXT (block);

	if (block && TREE_CODE (block) == FUNCTION_DECL)
	  m_fndecl = block;
	m_next_abstract_origin = NULL;
      }
  }

  tree m_abstract_origin;
  location_t m_callsite;
  tree m_fndecl;
  tree m_next_abstract_origin;
};

#endif /* GCC_ANALYZER_INLINING_ITERATOR_H */
