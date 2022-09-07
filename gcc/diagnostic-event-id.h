/* A class for referring to events within a diagnostic_path.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DIAGNOSTIC_EVENT_ID_H
#define GCC_DIAGNOSTIC_EVENT_ID_H

/* A class for referring to events within a diagnostic_path.

   They are stored as 0-based offsets into the events, but
   printed (e.g. via %@) as 1-based numbers.

   For example, a 3-event path has event offsets 0, 1, and 2,
   which would be shown to the user as "(1)", "(2)" and "(3)".

   This has its own header so that pretty-print.cc can use this
   to implement "%@" without bringing in all of diagnostic_path
   (which e.g. refers to "tree").  */

class diagnostic_event_id_t
{
 public:
  diagnostic_event_id_t () : m_index (UNKNOWN_EVENT_IDX) {}
  diagnostic_event_id_t (int zero_based_idx) : m_index (zero_based_idx) {}

  bool known_p () const { return m_index != UNKNOWN_EVENT_IDX; }

  int one_based () const
  {
    gcc_assert (known_p ());
    return m_index + 1;
  }

 private:
  static const int UNKNOWN_EVENT_IDX = -1;
  int m_index; // zero-based
};

/* A pointer to a diagnostic_event_id_t, for use with the "%@" format
   code, which will print a 1-based representation for it, with suitable
   colorization, e.g. "(1)".
   The %@ format code requires that known_p be true for the event ID. */
typedef diagnostic_event_id_t *diagnostic_event_id_ptr;

#endif /* ! GCC_DIAGNOSTIC_EVENT_ID_H */
