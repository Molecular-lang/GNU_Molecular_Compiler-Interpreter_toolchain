/* Base configuration file for all Phoenix-RTOS targets. */

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()           \
    do {                                   \
      builtin_define_std ("phoenix");      \
      builtin_define_std ("unix");         \
      builtin_assert ("system=phoenix");   \
      builtin_assert ("system=unix");      \
    } while (0)

#define STD_LIB_SPEC "%{!shared:%{g*:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}}"

/* This will prevent selecting 'unsigned long int' instead of 'unsigned int' as 'uint32_t' in stdint-newlib.h. */
#undef STDINT_LONG32
#define STDINT_LONG32		0
