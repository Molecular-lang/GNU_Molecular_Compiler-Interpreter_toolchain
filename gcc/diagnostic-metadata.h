/* Additional metadata for a diagnostic.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DIAGNOSTIC_METADATA_H
#define GCC_DIAGNOSTIC_METADATA_H

/* A bundle of additional metadata that can be associated with a
   diagnostic.

   This supports an optional CWE identifier, and zero or more
   "rules".  */

class diagnostic_metadata
{
 public:
  /* Abstract base class for referencing a rule that has been violated,
     such as within a coding standard, or within a specification.  */
  class rule
  {
  public:
    virtual char *make_description () const = 0;
    virtual char *make_url () const = 0;
  };

  /* Concrete subclass.  */
  class precanned_rule : public rule
  {
  public:
    precanned_rule (const char *desc, const char *url)
    : m_desc (desc), m_url (url)
    {}

    char *make_description () const final override
    {
      return m_desc ? xstrdup (m_desc) : NULL;
    }

    char *make_url () const final override
    {
      return m_url ? xstrdup (m_url) : NULL;
    }

  private:
    const char *m_desc;
    const char *m_url;
  };

  diagnostic_metadata () : m_cwe (0) {}

  void add_cwe (int cwe) { m_cwe = cwe; }
  int get_cwe () const { return m_cwe; }

  /* Associate R with the diagnostic.  R must outlive
     the metadata.  */
  void add_rule (const rule &r)
  {
    m_rules.safe_push (&r);
  }

  unsigned get_num_rules () const { return m_rules.length (); }
  const rule &get_rule (unsigned idx) const { return *(m_rules[idx]); }

 private:
  int m_cwe;
  auto_vec<const rule *> m_rules;
};

#endif /* ! GCC_DIAGNOSTIC_METADATA_H */
