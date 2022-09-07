/* decSingle module for the decNumber C Library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* ------------------------------------------------------------------ */
/* decSingle.c -- decSingle operations module			      */
/* ------------------------------------------------------------------ */

#include "decContext.h"       /* public includes */
#include "decSingle.h"	      /* public includes */

/* Constant mappings for shared code */
#define DECPMAX     DECSINGLE_Pmax
#define DECEMIN     DECSINGLE_Emin
#define DECEMAX     DECSINGLE_Emax
#define DECEMAXD    DECSINGLE_EmaxD
#define DECBYTES    DECSINGLE_Bytes
#define DECSTRING   DECSINGLE_String
#define DECECONL    DECSINGLE_EconL
#define DECBIAS     DECSINGLE_Bias
#define DECLETS     DECSINGLE_Declets
#define DECQTINY    (-DECSINGLE_Bias)
/* parameters of next-wider format */
#define DECWBYTES   DECDOUBLE_Bytes
#define DECWPMAX    DECDOUBLE_Pmax
#define DECWECONL   DECDOUBLE_EconL
#define DECWBIAS    DECDOUBLE_Bias

/* Type and function mappings for shared code */
#define decFloat		   decSingle	  /* Type name */
#define decFloatWider		   decDouble	  /* Type name */

/* Utility (binary results, extractors, etc.) */
#define decFloatFromBCD 	   decSingleFromBCD
#define decFloatFromPacked	   decSingleFromPacked
#define decFloatFromPackedChecked  decSingleFromPackedChecked
#define decFloatFromString	   decSingleFromString
#define decFloatFromWider	   decSingleFromWider
#define decFloatGetCoefficient	   decSingleGetCoefficient
#define decFloatGetExponent	   decSingleGetExponent
#define decFloatSetCoefficient	   decSingleSetCoefficient
#define decFloatSetExponent	   decSingleSetExponent
#define decFloatShow		   decSingleShow
#define decFloatToBCD		   decSingleToBCD
#define decFloatToEngString	   decSingleToEngString
#define decFloatToPacked	   decSingleToPacked
#define decFloatToString	   decSingleToString
#define decFloatToWider 	   decSingleToWider
#define decFloatZero		   decSingleZero

/* Non-computational */
#define decFloatRadix		   decSingleRadix
#define decFloatVersion 	   decSingleVersion

#include "decNumberLocal.h"   /* local includes (need DECPMAX) */
#include "decCommon.c"	      /* non-basic decFloat routines */
/* [Do not include decBasic.c for decimal32] */

