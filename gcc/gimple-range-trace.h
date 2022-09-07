/* Header file for the GIMPLE range tracing/debugging facilties.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_RANGE_TRACE_H
#define GCC_GIMPLE_RANGE_TRACE_H

// This class manages range tracing for the ranger and gori components.
// Tracing will provide a unique integer index whenever a new trace
// is started. This can be used to identify where a calculation has gone wrong.

class range_tracer
{
public:
  range_tracer (const char *name = "");
  unsigned header (const char *str);
  void trailer (unsigned counter, const char *caller, bool result, tree name,
		const vrange &r);
  void print (unsigned counter, const char *str);
  inline void enable_trace () { tracing = true; }
  inline void disable_trace () { tracing = false; }
  virtual void breakpoint (unsigned index);
private:
  unsigned do_header (const char *str);
  void print_prefix (unsigned idx, bool blanks);
  static const unsigned bump = 2;
  unsigned indent;
  static const unsigned name_len = 100;
  char component[name_len];
  bool tracing;
};


// If tracing is enabled, start a new trace header, returning the trace index.
// Otherwise return 0.

inline unsigned
range_tracer::header (const char *str)
{
  if (tracing)
    return do_header (str);
  return 0;
}

// RAII class to change current dump_file and dump_flags, and restore
// when the object goes out of scope.

class push_dump_file
{
public:
  push_dump_file (FILE *, dump_flags_t);
  ~push_dump_file ();
private:
  FILE *old_dump_file;
  dump_flags_t old_dump_flags;
};

void dump_ranger (FILE *);
void dump_ranger (FILE *, const vec<basic_block> &path);

#endif // GCC_GIMPLE_RANGE_TRACE_H
