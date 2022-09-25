/* RTL specific diagnostic subroutines for GCC
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl-error.h"
#include "diagnostic.h"
#include "intl.h"

static location_t location_for_asm (const rtx_insn *);
static void diagnostic_for_asm (const rtx_insn *, const char *, va_list *,
				diagnostic_t) ATTRIBUTE_GCC_DIAG(2,0);

/* Figure the location of the given INSN.  */
static location_t
location_for_asm (const rtx_insn *insn)
{
  rtx body = PATTERN (insn);
  rtx asmop;
  location_t loc;

  /* Find the (or one of the) ASM_OPERANDS in the insn.  */
  if (GET_CODE (body) == SET && GET_CODE (SET_SRC (body)) == ASM_OPERANDS)
    asmop = SET_SRC (body);
  else if (GET_CODE (body) == ASM_OPERANDS)
    asmop = body;
  else if (GET_CODE (body) == PARALLEL
	   && GET_CODE (XVECEXP (body, 0, 0)) == SET)
    asmop = SET_SRC (XVECEXP (body, 0, 0));
  else if (GET_CODE (body) == PARALLEL
	   && GET_CODE (XVECEXP (body, 0, 0)) == ASM_OPERANDS)
    asmop = XVECEXP (body, 0, 0);
  else
    asmop = NULL;

  if (asmop)
    loc = ASM_OPERANDS_SOURCE_LOCATION (asmop);
  else
    loc = input_location;
  return loc;
}

/* Report a diagnostic MESSAGE (an error or a WARNING) at the line number
   of the insn INSN.  This is used only when INSN is an `asm' with operands,
   and each ASM_OPERANDS records its own source file and line.  */
static void
diagnostic_for_asm (const rtx_insn *insn, const char *msg, va_list *args_ptr,
		    diagnostic_t kind)
{
  diagnostic_info diagnostic;
  rich_location richloc (line_table, location_for_asm (insn));

  diagnostic_set_info (&diagnostic, msg, args_ptr,
		       &richloc, kind);
  diagnostic_report_diagnostic (global_dc, &diagnostic);
}

void
error_for_asm (const rtx_insn *insn, const char *gmsgid, ...)
{
  va_list ap;

  va_start (ap, gmsgid);
  diagnostic_for_asm (insn, gmsgid, &ap, DK_ERROR);
  va_end (ap);
}

void
warning_for_asm (const rtx_insn *insn, const char *gmsgid, ...)
{
  va_list ap;

  va_start (ap, gmsgid);
  diagnostic_for_asm (insn, gmsgid, &ap, DK_WARNING);
  va_end (ap);
}

void
_fatal_insn (const char *msgid, const_rtx insn, const char *file, int line,
	     const char *function)
{
  error ("%s", _(msgid));

  /* The above incremented error_count, but isn't an error that we want to
     count, so reset it here.  */
  errorcount--;

  debug_rtx (insn);
  fancy_abort (file, line, function);
}

void
_fatal_insn_not_found (const_rtx insn, const char *file, int line,
		       const char *function)
{
  if (INSN_CODE (insn) < 0)
    _fatal_insn ("unrecognizable insn:", insn, file, line, function);
  else
    _fatal_insn ("insn does not satisfy its constraints:",
		insn, file, line, function);
}
