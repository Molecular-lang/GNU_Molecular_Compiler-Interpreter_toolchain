/* context.h - Holder for global state
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_CONTEXT_H
#define GCC_CONTEXT_H

namespace gcc {

class pass_manager;
class dump_manager;

/* GCC's internal state can be divided into zero or more
   "parallel universe" of state; an instance of this class is one such
   context of state.  */
class context
{
public:
  context ();
  ~context ();

  /* The flag shows if there are symbols to be streamed for offloading.  */
  bool have_offload;

  /* Pass-management.  */

  void set_passes (pass_manager *m)
  {
    gcc_assert (!m_passes);
    m_passes = m;
  }

  pass_manager *get_passes () { gcc_assert (m_passes); return m_passes; }

  /* Handling dump files.  */

  dump_manager *get_dumps () {gcc_assert (m_dumps); return m_dumps; }

private:
  /* Pass-management.  */
  pass_manager *m_passes;

  /* Dump files.  */
  dump_manager *m_dumps;

}; // class context

} // namespace gcc

/* The global singleton context aka "g".
   (the name is chosen to be easy to type in a debugger).  */
extern gcc::context *g;

#endif /* ! GCC_CONTEXT_H */
