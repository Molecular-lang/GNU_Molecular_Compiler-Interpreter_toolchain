/* Helper code for graphviz output.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "graphviz.h"

/* graphviz_out's ctor, wrapping PP.  */

graphviz_out::graphviz_out (pretty_printer *pp)
: m_pp (pp),
  m_indent (0)
{
}

/* Formatted print of FMT.  */

void
graphviz_out::print (const char *fmt, ...)
{
  text_info text;
  va_list ap;

  va_start (ap, fmt);
  text.err_no = errno;
  text.args_ptr = &ap;
  text.format_spec = fmt;
  pp_format (m_pp, &text);
  pp_output_formatted_text (m_pp);
  va_end (ap);
}

/* Formatted print of FMT.  The text is indented by the current
   indent, and a newline is added.  */

void
graphviz_out::println (const char *fmt, ...)
{
  text_info text;
  va_list ap;

  write_indent ();

  va_start (ap, fmt);
  text.err_no = errno;
  text.args_ptr = &ap;
  text.format_spec = fmt;
  pp_format (m_pp, &text);
  pp_output_formatted_text (m_pp);
  va_end (ap);

  pp_newline (m_pp);
}

/* Print the current indent to the underlying pp.  */

void
graphviz_out::write_indent ()
{
  for (int i = 0; i < m_indent * 2; ++i)
    pp_space (m_pp);
}

/* Write the start of an HTML-like row via <TR>, writing to the stream
   so that followup text can be escaped.  */

void
graphviz_out::begin_tr ()
{
  pp_string (m_pp, "<TR>");
  pp_write_text_to_stream (m_pp);
}

/* Write the end of an HTML-like row via </TR>, writing to the stream
   so that followup text can be escaped.  */

void
graphviz_out::end_tr ()
{
  pp_string (m_pp, "</TR>");
  pp_write_text_to_stream (m_pp);
}

/* Write the start of an HTML-like <TD>, writing to the stream
   so that followup text can be escaped.  */

void
graphviz_out::begin_td ()
{
  pp_string (m_pp, "<TD ALIGN=\"LEFT\">");
  pp_write_text_to_stream (m_pp);
}

/* Write the end of an HTML-like </TD>, writing to the stream
   so that followup text can be escaped.  */

void
graphviz_out::end_td ()
{
  pp_string (m_pp, "</TD>");
  pp_write_text_to_stream (m_pp);
}

/* Write the start of an HTML-like row via <TR><TD>, writing to the stream
   so that followup text can be escaped.  */

void
graphviz_out::begin_trtd ()
{
  pp_string (m_pp, "<TR><TD ALIGN=\"LEFT\">");
  pp_write_text_to_stream (m_pp);
}

/* Write the end of an HTML-like row via </TD></TR>, writing to the stream
   so that followup text can be escaped.  */

void
graphviz_out::end_tdtr ()
{
  pp_string (m_pp, "</TD></TR>");
  pp_write_text_to_stream (m_pp);
}
