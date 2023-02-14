/* bignum.h-arbitrary precision integers */

/***********************************************************************\
 *									*
 *	Arbitrary-precision integer arithmetic.				*
 *	For speed, we work in groups of bits, even though this		*
 *	complicates algorithms.						*
 *	Each group of bits is called a 'littlenum'.			*
 *	A bunch of littlenums representing a (possibly large)		*
 *	integer is called a 'bignum'.					*
 *	Bignums are >= 0.						*
 *									*
 \***********************************************************************/

#define	LITTLENUM_NUMBER_OF_BITS	(16)
#define	LITTLENUM_RADIX			(1 << LITTLENUM_NUMBER_OF_BITS)
#define	LITTLENUM_MASK			(0xFFFF)
#define LITTLENUM_SHIFT			(1)
#define CHARS_PER_LITTLENUM		(1 << LITTLENUM_SHIFT)
#ifndef BITS_PER_CHAR
#define BITS_PER_CHAR			(8)
#endif

typedef unsigned short LITTLENUM_TYPE;
