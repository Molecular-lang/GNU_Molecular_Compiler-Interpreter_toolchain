/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _LIMITS_H___
#define _LIMITS_H___

/* Number of bits in a `char'.  */
#undef CHAR_BIT
#define CHAR_BIT __CHAR_BIT__

/* Maximum length of a multibyte character.  */
#ifndef MB_LEN_MAX
#define MB_LEN_MAX 1
#endif

/* Minimum and maximum values a `signed char' can hold.  */
#undef SCHAR_MIN
#define SCHAR_MIN (-SCHAR_MAX - 1)
#undef SCHAR_MAX
#define SCHAR_MAX __SCHAR_MAX__

/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
#undef UCHAR_MAX
#if __SCHAR_MAX__ == __INT_MAX__
# define UCHAR_MAX (SCHAR_MAX * 2U + 1U)
#else
# define UCHAR_MAX (SCHAR_MAX * 2 + 1)
#endif

/* Minimum and maximum values a `char' can hold.  */
#ifdef __CHAR_UNSIGNED__
# undef CHAR_MIN
# if __SCHAR_MAX__ == __INT_MAX__
#  define CHAR_MIN 0U
# else
#  define CHAR_MIN 0
# endif
# undef CHAR_MAX
# define CHAR_MAX UCHAR_MAX
#else
# undef CHAR_MIN
# define CHAR_MIN SCHAR_MIN
# undef CHAR_MAX
# define CHAR_MAX SCHAR_MAX
#endif

/* Minimum and maximum values a `signed short int' can hold.  */
#undef SHRT_MIN
#define SHRT_MIN (-SHRT_MAX - 1)
#undef SHRT_MAX
#define SHRT_MAX __SHRT_MAX__

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
#undef USHRT_MAX
#if __SHRT_MAX__ == __INT_MAX__
# define USHRT_MAX (SHRT_MAX * 2U + 1U)
#else
# define USHRT_MAX (SHRT_MAX * 2 + 1)
#endif

/* Minimum and maximum values a `signed int' can hold.  */
#undef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#undef INT_MAX
#define INT_MAX __INT_MAX__

/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
#undef UINT_MAX
#define UINT_MAX (INT_MAX * 2U + 1U)

/* Minimum and maximum values a `signed long int' can hold.
   (Same as `int').  */
#undef LONG_MIN
#define LONG_MIN (-LONG_MAX - 1L)
#undef LONG_MAX
#define LONG_MAX __LONG_MAX__

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
#undef ULONG_MAX
#define ULONG_MAX (LONG_MAX * 2UL + 1UL)

#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/* Minimum and maximum values a `signed long long int' can hold.  */
# undef LLONG_MIN
# define LLONG_MIN (-LLONG_MAX - 1LL)
# undef LLONG_MAX
# define LLONG_MAX __LONG_LONG_MAX__

/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0).  */
# undef ULLONG_MAX
# define ULLONG_MAX (LLONG_MAX * 2ULL + 1ULL)
#endif

#if defined (__GNU_LIBRARY__) ? defined (__USE_GNU) : !defined (__STRICT_ANSI__)
/* Minimum and maximum values a `signed long long int' can hold.  */
# undef LONG_LONG_MIN
# define LONG_LONG_MIN (-LONG_LONG_MAX - 1LL)
# undef LONG_LONG_MAX
# define LONG_LONG_MAX __LONG_LONG_MAX__

/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0).  */
# undef ULONG_LONG_MAX
# define ULONG_LONG_MAX (LONG_LONG_MAX * 2ULL + 1ULL)
#endif

#if (defined __STDC_WANT_IEC_60559_BFP_EXT__ \
     || (defined (__STDC_VERSION__) && __STDC_VERSION__ > 201710L))
/* TS 18661-1 / C2X widths of integer types.  */
# undef CHAR_WIDTH
# define CHAR_WIDTH __SCHAR_WIDTH__
# undef SCHAR_WIDTH
# define SCHAR_WIDTH __SCHAR_WIDTH__
# undef UCHAR_WIDTH
# define UCHAR_WIDTH __SCHAR_WIDTH__
# undef SHRT_WIDTH
# define SHRT_WIDTH __SHRT_WIDTH__
# undef USHRT_WIDTH
# define USHRT_WIDTH __SHRT_WIDTH__
# undef INT_WIDTH
# define INT_WIDTH __INT_WIDTH__
# undef UINT_WIDTH
# define UINT_WIDTH __INT_WIDTH__
# undef LONG_WIDTH
# define LONG_WIDTH __LONG_WIDTH__
# undef ULONG_WIDTH
# define ULONG_WIDTH __LONG_WIDTH__
# undef LLONG_WIDTH
# define LLONG_WIDTH __LONG_LONG_WIDTH__
# undef ULLONG_WIDTH
# define ULLONG_WIDTH __LONG_LONG_WIDTH__
#endif

#if defined (__STDC_VERSION__) && __STDC_VERSION__ > 201710L
/* C2X width and limit of _Bool.  */
# undef BOOL_MAX
# define BOOL_MAX 1
# undef BOOL_WIDTH
# define BOOL_WIDTH 1
#endif

#endif /* _LIMITS_H___ */
