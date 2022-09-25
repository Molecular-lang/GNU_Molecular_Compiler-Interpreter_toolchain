/* RTL hash functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "rtlhash.h"

namespace inchash
{

/* Iteratively hash rtx X into HSTATE.  */

void
add_rtx (const_rtx x, hash &hstate)
{
  enum rtx_code code;
  machine_mode mode;
  int i, j;
  const char *fmt;

  if (x == NULL_RTX)
    return;
  code = GET_CODE (x);
  hstate.add_object (code);
  mode = GET_MODE (x);
  hstate.add_object (mode);
  switch (code)
    {
    case REG:
      hstate.add_int (REGNO (x));
      return;
    case CONST_INT:
      hstate.add_object (INTVAL (x));
      return;
    case CONST_WIDE_INT:
      for (i = 0; i < CONST_WIDE_INT_NUNITS (x); i++)
	hstate.add_object (CONST_WIDE_INT_ELT (x, i));
      return;
    case CONST_POLY_INT:
      for (i = 0; i < NUM_POLY_INT_COEFFS; ++i)
	hstate.add_wide_int (CONST_POLY_INT_COEFFS (x)[i]);
      break;
    case SYMBOL_REF:
      if (XSTR (x, 0))
	hstate.add (XSTR (x, 0), strlen (XSTR (x, 0)) + 1);
      return;
    case LABEL_REF:
    case DEBUG_EXPR:
    case VALUE:
    case SCRATCH:
    case CONST_DOUBLE:
    case CONST_FIXED:
    case DEBUG_IMPLICIT_PTR:
    case DEBUG_PARAMETER_REF:
      return;
    default:
      break;
    }

  fmt = GET_RTX_FORMAT (code);
  for (i = GET_RTX_LENGTH (code) - 1; i >= 0; i--)
    switch (fmt[i])
      {
      case 'w':
	hstate.add_hwi (XWINT (x, i));
	break;
      case 'n':
      case 'i':
	hstate.add_int (XINT (x, i));
	break;
      case 'p':
	hstate.add_poly_int (SUBREG_BYTE (x));
	break;
      case 'V':
      case 'E':
	j = XVECLEN (x, i);
	hstate.add_int (j);
	for (j = 0; j < XVECLEN (x, i); j++)
	  inchash::add_rtx (XVECEXP (x, i, j), hstate);
	break;
      case 'e':
	inchash::add_rtx (XEXP (x, i), hstate);
	break;
      case 'S':
      case 's':
	if (XSTR (x, i))
	  hstate.add (XSTR (x, 0), strlen (XSTR (x, 0)) + 1);
	break;
      default:
	break;
      }
}

}
