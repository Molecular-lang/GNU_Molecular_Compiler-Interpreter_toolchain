/* Packed decimal conversion module header for the decNumber C Library.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* ------------------------------------------------------------------ */
/* Packed Decimal conversion module header			      */
/* ------------------------------------------------------------------ */

#if !defined(DECPACKED)
  #define DECPACKED
  #define DECPNAME     "decPacked"			/* Short name */
  #define DECPFULLNAME "Packed Decimal conversions"   /* Verbose name */
  #define DECPAUTHOR   "Mike Cowlishaw" 	      /* Who to blame */

  #define DECPACKED_DefP 32		/* default precision	      */

  #ifndef  DECNUMDIGITS
    #define DECNUMDIGITS DECPACKED_DefP /* size if not already defined*/
  #endif
  #include "decNumber.h"		/* context and number library */

  /* Sign nibble constants					      */
  #if !defined(DECPPLUSALT)
    #define DECPPLUSALT  0x0A /* alternate plus  nibble 	      */
    #define DECPMINUSALT 0x0B /* alternate minus nibble 	      */
    #define DECPPLUS	 0x0C /* preferred plus  nibble 	      */
    #define DECPMINUS	 0x0D /* preferred minus nibble 	      */
    #define DECPPLUSALT2 0x0E /* alternate plus  nibble 	      */
    #define DECPUNSIGNED 0x0F /* alternate plus  nibble (unsigned)    */
  #endif

  /* ---------------------------------------------------------------- */
  /* decPacked public routines					      */
  /* ---------------------------------------------------------------- */

  #include "decPackedSymbols.h"

  /* Conversions						      */
  uint8_t * decPackedFromNumber(uint8_t *, int32_t, int32_t *,
				const decNumber *);
  decNumber * decPackedToNumber(const uint8_t *, int32_t, const int32_t *,
				decNumber *);

#endif
