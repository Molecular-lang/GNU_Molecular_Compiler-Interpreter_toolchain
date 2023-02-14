/* Definitions for <stdint.h> types on systems using Cygwin. */

#define SIG_ATOMIC_TYPE "int"

/* Exact-width integer types */

#define INT8_TYPE "signed char"
#define INT16_TYPE "short int"
#define INT32_TYPE "int"
#define INT64_TYPE (TARGET_64BIT ? "long int" : "long long int")

#define UINT8_TYPE "unsigned char"
#define UINT16_TYPE "short unsigned int"
#define UINT32_TYPE "unsigned int"
#define UINT64_TYPE (TARGET_64BIT ? "long unsigned int" : "long long unsigned int")

/* Minimum-width integer types */

#define INT_LEAST8_TYPE "signed char"
#define INT_LEAST16_TYPE "short int"
#define INT_LEAST32_TYPE "int"
#define INT_LEAST64_TYPE (TARGET_64BIT ? "long int" : "long long int")

#define UINT_LEAST8_TYPE "unsigned char"
#define UINT_LEAST16_TYPE "short unsigned int"
#define UINT_LEAST32_TYPE "unsigned int"
#define UINT_LEAST64_TYPE (TARGET_64BIT ? "long unsigned int" : "long long unsigned int")

/* Fastest minimum-width integer types */

#define INT_FAST8_TYPE "signed char"
#define INT_FAST16_TYPE (TARGET_64BIT ? "long int" : "int")
#define INT_FAST32_TYPE (TARGET_64BIT ? "long int" : "int")
#define INT_FAST64_TYPE (TARGET_64BIT ? "long int" : "long long int")

#define UINT_FAST8_TYPE "unsigned char"
#define UINT_FAST16_TYPE (TARGET_64BIT ? "long unsigned int" : "unsigned int")
#define UINT_FAST32_TYPE (TARGET_64BIT ? "long unsigned int" : "unsigned int")
#define UINT_FAST64_TYPE (TARGET_64BIT ? "long unsigned int" : "long long unsigned int")

/* Integer types capable of holding object pointers */

#define INTPTR_TYPE (TARGET_64BIT ? "long int" : "int")
#define UINTPTR_TYPE (TARGET_64BIT ? "long unsigned int" : "unsigned int")
