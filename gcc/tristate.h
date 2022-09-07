/* "True" vs "False" vs "Unknown".
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TRISTATE_H
#define GCC_TRISTATE_H

/* "True" vs "False" vs "Unknown".  */

class tristate {
 public:
  enum value {
    TS_UNKNOWN,
    TS_TRUE,
    TS_FALSE
  };

  tristate (enum value val) : m_value (val) {}
  tristate (bool val) : m_value (val ? TS_TRUE : TS_FALSE) {}
  static tristate unknown () { return tristate (TS_UNKNOWN); }

  const char *as_string () const;

  bool is_known () const { return m_value != TS_UNKNOWN; }
  bool is_true () const { return m_value == TS_TRUE; }
  bool is_false () const { return m_value == TS_FALSE; }

  tristate not_ () const;
  tristate or_ (tristate other) const;
  tristate and_ (tristate other) const;

  bool operator== (const tristate &other) const
  {
    return m_value == other.m_value;
  }

  bool operator!= (const tristate &other) const
  {
    return m_value != other.m_value;
  }

  enum value get_value () const { return m_value; }

 private:
  enum value m_value;
};

/* Overloaded boolean operators on tristates.  */

inline tristate
operator ! (tristate t)
{
  return t.not_ ();
}

inline tristate
operator || (tristate a, tristate b)
{
  return a.or_ (b);
}

inline tristate
operator && (tristate a, tristate b)
{
  return a.and_ (b);
}

#endif /* GCC_TRISTATE_H */
