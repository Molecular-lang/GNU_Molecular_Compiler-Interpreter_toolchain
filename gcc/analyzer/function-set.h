/* Sets of function names.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_FUNCTION_SET_H
#define GCC_ANALYZER_FUNCTION_SET_H

namespace ana {

/* A set of names.  */

class function_set
{
public:
  /* Construct from a sorted array NAMES of size COUNT.  */
  function_set (const char * const *names, size_t count)
  : m_names (names), m_count (count)
  {
  }

  bool contains_name_p (const char *name) const;
  bool contains_decl_p (tree fndecl) const;

  void assert_sorted () const;
  void assert_sane () const;

private:
  const char * const *m_names; // must be sorted
  size_t m_count;
};

} // namespace ana

#endif /* GCC_ANALYZER_FUNCTION_SET_H */
