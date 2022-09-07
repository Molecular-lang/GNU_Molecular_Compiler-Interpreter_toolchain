/* Shared escaped string class.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ESCAPED_STRING_H
#define GCC_ESCAPED_STRING_H

#include <cstdlib>

/* A class to handle converting a string that might contain
   control characters, (eg newline, form-feed, etc), into one
   in which contains escape sequences instead.  */

class escaped_string
{
 public:
  escaped_string () { m_owned = false; m_str = NULL; };
  ~escaped_string () { if (m_owned) free (m_str); }
  operator const char *() const { return m_str; }
  void escape (const char *);
 private:
  escaped_string(const escaped_string&) {}
  escaped_string& operator=(const escaped_string&) { return *this; }
  char *m_str;
  bool  m_owned;
};

#endif /* ! GCC_ESCAPED_STRING_H */
