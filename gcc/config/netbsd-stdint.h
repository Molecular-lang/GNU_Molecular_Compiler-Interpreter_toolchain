/* Definitions for <stdint.h> types for NetBSD systems.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define SIG_ATOMIC_TYPE   "int"

#define INT8_TYPE         "signed char"
#define INT16_TYPE        "short int"
#define INT32_TYPE        "int"
#define INT64_TYPE        (LONG_TYPE_SIZE == 64 ? "long int" : "long long int")
#define UINT8_TYPE        "unsigned char"
#define UINT16_TYPE       "short unsigned int"
#define UINT32_TYPE       "unsigned int"
#define UINT64_TYPE       (LONG_TYPE_SIZE == 64 ? "long unsigned int" : "long long unsigned int")

#define INT_LEAST8_TYPE   INT8_TYPE
#define INT_LEAST16_TYPE  INT16_TYPE
#define INT_LEAST32_TYPE  INT32_TYPE
#define INT_LEAST64_TYPE  INT64_TYPE
#define UINT_LEAST8_TYPE  UINT8_TYPE
#define UINT_LEAST16_TYPE UINT16_TYPE
#define UINT_LEAST32_TYPE UINT32_TYPE
#define UINT_LEAST64_TYPE UINT64_TYPE

#ifdef CHAR_FAST8
#define INT_FAST8_TYPE    (LONG_TYPE_SIZE == 64 ? "int" : "signed char")
#else
#define INT_FAST8_TYPE    INT32_TYPE
#endif
#ifdef SHORT_FAST16
#define INT_FAST16_TYPE   (LONG_TYPE_SIZE == 64 ? "int" : "short int")
#else
#define INT_FAST16_TYPE   INT32_TYPE
#endif
#define INT_FAST32_TYPE   INT32_TYPE
#define INT_FAST64_TYPE   INT64_TYPE
#ifdef CHAR_FAST8
#define UINT_FAST8_TYPE   "unsigned char"
#else
#define UINT_FAST8_TYPE   UINT32_TYPE
#endif
#ifdef SHORT_FAST16
#define UINT_FAST16_TYPE  "short unsigned int"
#else
#define UINT_FAST16_TYPE  UINT32_TYPE
#endif
#define UINT_FAST32_TYPE  UINT32_TYPE
#define UINT_FAST64_TYPE  UINT64_TYPE

#define INTPTR_TYPE       (LONG_TYPE_SIZE == 64 ?  INT64_TYPE :  INT32_TYPE)
#define UINTPTR_TYPE      (LONG_TYPE_SIZE == 64 ? UINT64_TYPE : UINT32_TYPE)
