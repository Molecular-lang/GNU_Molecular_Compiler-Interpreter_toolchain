/* Interface between analyzer and frontends.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_LANGUAGE_H
#define GCC_ANALYZER_LANGUAGE_H

#if ENABLE_ANALYZER

namespace ana {

/* Abstract base class for representing a specific TU
   to the analyzer.  */

class translation_unit
{
 public:
  /* Attempt to look up an  value for identifier ID (e.g. in the headers that
     have been seen).  If it is defined and an integer (e.g. either as a
     macro or enum), return the INTEGER_CST value, otherwise return NULL.  */
  virtual tree lookup_constant_by_id (tree id) const = 0;
};

/* Analyzer hook for frontends to call at the end of the TU.  */

void on_finish_translation_unit (const translation_unit &tu);

} // namespace ana

#endif /* #if ENABLE_ANALYZER */

#endif /* GCC_ANALYZER_LANGUAGE_H */
