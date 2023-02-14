/* Local definitions for use with the decNumber C Library. */

#if !defined(DECIMAL128LOCAL)

/* The compiler needs sign manipulation functions for decimal128 which
   are not part of the decNumber package.  */

/* Set sign; this assumes the sign was previously zero.  */
#define decimal128SetSign(d,b) \
  { (d)->bytes[WORDS_BIGENDIAN ? 0 : 15] |= ((unsigned) (b) << 7); }

/* Clear sign.  */
#define decimal128ClearSign(d) \
  { (d)->bytes[WORDS_BIGENDIAN ? 0 : 15] &= ~0x80; }

/* Flip sign.  */
#define decimal128FlipSign(d) \
  { (d)->bytes[WORDS_BIGENDIAN ? 0 : 15] ^= 0x80; }

#endif
