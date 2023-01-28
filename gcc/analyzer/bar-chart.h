/* Support for plotting bar charts in dumps.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_BAR_CHART_H
#define GCC_ANALYZER_BAR_CHART_H

namespace ana {

/* A class for printing bar charts to a pretty_printer.

   TODO(stage1): move to gcc subdir? */

class bar_chart
{
public:
  typedef unsigned long value_t;

  /* Add an item, taking a copy of NAME.  */
  void add_item (const char *name, value_t value);

  /* Print the data to PP.  */
  void print (pretty_printer *pp) const;

private:
  struct item
  {
    item (const char *name, value_t value)
    : m_name (xstrdup (name)), m_strlen (strlen (name)) , m_value (value) {}
    ~item () { free (m_name); }

    char *m_name;
    size_t m_strlen;
    value_t m_value;
  };

  static void print_padding (pretty_printer *pp, size_t count);

  auto_delete_vec<item> m_items;
};

} // namespace ana

#endif /* GCC_ANALYZER_BAR_CHART_H */
