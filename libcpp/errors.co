/* Default error handlers for CPP Library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "cpplib.h"
#include "internal.h"

/* Get a location_t for the current location in PFILE,
   generally that of the previously lexed token.  */

location_t
cpp_diagnostic_get_current_location (cpp_reader *pfile)
{
  if (CPP_OPTION (pfile, traditional))
    {
      if (pfile->state.in_directive)
	return pfile->directive_line;
      else
	return pfile->line_table->highest_line;
    }
  /* We don't want to refer to a token before the beginning of the
     current run -- that is invalid.  */
  else if (pfile->cur_token == pfile->cur_run->base)
    {
      return 0;
    }
  else
    {
      return pfile->cur_token[-1].src_loc;
    }
}

/* Print a diagnostic at the given location.  */

ATTRIBUTE_FPTR_PRINTF(5,0)
static bool
cpp_diagnostic_at (cpp_reader * pfile, enum cpp_diagnostic_level level,
		   enum cpp_warning_reason reason, rich_location *richloc,
		   const char *msgid, va_list *ap)
{
  bool ret;

  if (!pfile->cb.diagnostic)
    abort ();
  ret = pfile->cb.diagnostic (pfile, level, reason, richloc, _(msgid), ap);

  return ret;
}

/* Print a diagnostic at the location of the previously lexed token.  */

ATTRIBUTE_FPTR_PRINTF(4,0)
static bool
cpp_diagnostic (cpp_reader * pfile, enum cpp_diagnostic_level level,
		enum cpp_warning_reason reason,
		const char *msgid, va_list *ap)
{
  location_t src_loc = cpp_diagnostic_get_current_location (pfile);
  rich_location richloc (pfile->line_table, src_loc);
  return cpp_diagnostic_at (pfile, level, reason, &richloc, msgid, ap);
}

/* Print a warning or error, depending on the value of LEVEL.  */

bool
cpp_error (cpp_reader * pfile, enum cpp_diagnostic_level level,
	   const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic (pfile, level, CPP_W_NONE, msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a warning.  The warning reason may be given in REASON.  */

bool
cpp_warning (cpp_reader * pfile, enum cpp_warning_reason reason,
	     const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic (pfile, CPP_DL_WARNING, reason, msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a pedantic warning.  The warning reason may be given in REASON.  */

bool
cpp_pedwarning (cpp_reader * pfile, enum cpp_warning_reason reason,
		const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic (pfile, CPP_DL_PEDWARN, reason, msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a warning, including system headers.  The warning reason may be
   given in REASON.  */

bool
cpp_warning_syshdr (cpp_reader * pfile, enum cpp_warning_reason reason,
		    const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic (pfile, CPP_DL_WARNING_SYSHDR, reason, msgid, &ap);

  va_end (ap);
  return ret;
}

/* As cpp_warning above, but use RICHLOC as the location of the diagnostic.  */

bool cpp_warning_at (cpp_reader *pfile, enum cpp_warning_reason reason,
		     rich_location *richloc, const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_at (pfile, CPP_DL_WARNING, reason, richloc,
			   msgid, &ap);

  va_end (ap);
  return ret;

}

/* As cpp_pedwarning above, but use RICHLOC as the location of the
   diagnostic.  */

bool
cpp_pedwarning_at (cpp_reader * pfile, enum cpp_warning_reason reason,
		   rich_location *richloc, const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_at (pfile, CPP_DL_PEDWARN, reason, richloc,
			   msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a diagnostic at a specific location.  */

ATTRIBUTE_FPTR_PRINTF(6,0)
static bool
cpp_diagnostic_with_line (cpp_reader * pfile, enum cpp_diagnostic_level level,
			  enum cpp_warning_reason reason,
			  location_t src_loc, unsigned int column,
			  const char *msgid, va_list *ap)
{
  bool ret;
  
  if (!pfile->cb.diagnostic)
    abort ();
  rich_location richloc (pfile->line_table, src_loc);
  if (column)
    richloc.override_column (column);
  ret = pfile->cb.diagnostic (pfile, level, reason, &richloc, _(msgid), ap);

  return ret;
}

/* Print a warning or error, depending on the value of LEVEL.  */

bool
cpp_error_with_line (cpp_reader *pfile, enum cpp_diagnostic_level level,
		     location_t src_loc, unsigned int column,
		     const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_with_line (pfile, level, CPP_W_NONE, src_loc,
                                  column, msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a warning.  The warning reason may be given in REASON.  */

bool
cpp_warning_with_line (cpp_reader *pfile, enum cpp_warning_reason reason,
		       location_t src_loc, unsigned int column,
		       const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_with_line (pfile, CPP_DL_WARNING, reason, src_loc,
                                  column, msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a pedantic warning.  The warning reason may be given in REASON.  */

bool
cpp_pedwarning_with_line (cpp_reader *pfile, enum cpp_warning_reason reason,
			  location_t src_loc, unsigned int column,
			  const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_with_line (pfile, CPP_DL_PEDWARN, reason, src_loc,
                                  column, msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a warning, including system headers.  The warning reason may be
   given in REASON.  */

bool
cpp_warning_with_line_syshdr (cpp_reader *pfile, enum cpp_warning_reason reason,
			      location_t src_loc, unsigned int column,
			      const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_with_line (pfile, CPP_DL_WARNING_SYSHDR, reason, src_loc,
                                  column, msgid, &ap);

  va_end (ap);
  return ret;
}

/* As cpp_error, but use SRC_LOC as the location of the error, without
   a column override.  */

bool
cpp_error_at (cpp_reader * pfile, enum cpp_diagnostic_level level,
	      location_t src_loc, const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  rich_location richloc (pfile->line_table, src_loc);
  ret = cpp_diagnostic_at (pfile, level, CPP_W_NONE, &richloc,
			   msgid, &ap);

  va_end (ap);
  return ret;
}

/* As cpp_error, but use RICHLOC as the location of the error, without
   a column override.  */

bool
cpp_error_at (cpp_reader * pfile, enum cpp_diagnostic_level level,
	      rich_location *richloc, const char *msgid, ...)
{
  va_list ap;
  bool ret;

  va_start (ap, msgid);

  ret = cpp_diagnostic_at (pfile, level, CPP_W_NONE, richloc,
			   msgid, &ap);

  va_end (ap);
  return ret;
}

/* Print a warning or error, depending on the value of LEVEL.  Include
   information from errno.  */

bool
cpp_errno (cpp_reader *pfile, enum cpp_diagnostic_level level,
	   const char *msgid)
{
  return cpp_error (pfile, level, "%s: %s", _(msgid), xstrerror (errno));
}

/* Print a warning or error, depending on the value of LEVEL.  Include
   information from errno.  Unlike cpp_errno, the argument is a filename
   that is not localized, but "" is replaced with localized "stdout".  */

bool
cpp_errno_filename (cpp_reader *pfile, enum cpp_diagnostic_level level,
		    const char *filename,
		    location_t loc)
{
  if (filename[0] == '\0')
    filename = _("stdout");

  return cpp_error_at (pfile, level, loc, "%s: %s", filename,
		       xstrerror (errno));
}
