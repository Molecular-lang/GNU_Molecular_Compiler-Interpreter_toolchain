/* Helper code for graphviz output.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GRAPHVIZ_H
#define GCC_GRAPHVIZ_H

#include "pretty-print.h" /* for ATTRIBUTE_GCC_PPDIAG.  */

/* A class for writing .dot output to a pretty_printer with
   indentation to show nesting.  */

class graphviz_out {
 public:
  graphviz_out (pretty_printer *pp);

  void print (const char *fmt, ...)
    ATTRIBUTE_GCC_PPDIAG(2,3);
  void println (const char *fmt, ...)
    ATTRIBUTE_GCC_PPDIAG(2,3);

  void indent () { m_indent++; }
  void outdent () { m_indent--; }

  void write_indent ();

  void begin_tr ();
  void end_tr ();

  void begin_td ();
  void end_td ();

  void begin_trtd ();
  void end_tdtr ();

  pretty_printer *get_pp () const { return m_pp; }

 private:
  pretty_printer *m_pp;
  int m_indent;
};

#endif /* GCC_GRAPHVIZ_H */
