/* simple.c -- The backtrace_simple function.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"

#include "unwind.h"
#include "backtrace.h"

/* The simple_backtrace routine.  */

/* Data passed through _Unwind_Backtrace.  */

struct backtrace_simple_data
{
  /* Number of frames to skip.  */
  int skip;
  /* Library state.  */
  struct backtrace_state *state;
  /* Callback routine.  */
  backtrace_simple_callback callback;
  /* Error callback routine.  */
  backtrace_error_callback error_callback;
  /* Data to pass to callback routine.  */
  void *data;
  /* Value to return from backtrace.  */
  int ret;
};

/* Unwind library callback routine.  This is passed to
   _Unwind_Backtrace.  */

static _Unwind_Reason_Code
simple_unwind (struct _Unwind_Context *context, void *vdata)
{
  struct backtrace_simple_data *bdata = (struct backtrace_simple_data *) vdata;
  uintptr_t pc;
  int ip_before_insn = 0;

#ifdef HAVE_GETIPINFO
  pc = _Unwind_GetIPInfo (context, &ip_before_insn);
#else
  pc = _Unwind_GetIP (context);
#endif

  if (bdata->skip > 0)
    {
      --bdata->skip;
      return _URC_NO_REASON;
    }

  if (!ip_before_insn)
    --pc;

  bdata->ret = bdata->callback (bdata->data, pc);

  if (bdata->ret != 0)
    return _URC_END_OF_STACK;

  return _URC_NO_REASON;
}

/* Get a simple stack backtrace.  */

int __attribute__((noinline))
backtrace_simple (struct backtrace_state *state, int skip,
		  backtrace_simple_callback callback,
		  backtrace_error_callback error_callback, void *data)
{
  struct backtrace_simple_data bdata;

  bdata.skip = skip + 1;
  bdata.state = state;
  bdata.callback = callback;
  bdata.error_callback = error_callback;
  bdata.data = data;
  bdata.ret = 0;
  _Unwind_Backtrace (simple_unwind, &bdata);
  return bdata.ret;
}
