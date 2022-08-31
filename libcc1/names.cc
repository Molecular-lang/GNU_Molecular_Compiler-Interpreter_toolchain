/* String definitions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include <cc1plugin-config.h>
#include "names.hh"

#define GCC_METHOD0(R, N) const char *cc1_plugin::LANG::N = # N;
#define GCC_METHOD1(R, N, A) const char *cc1_plugin::LANG::N = # N;
#define GCC_METHOD2(R, N, A, B) const char *cc1_plugin::LANG::N = # N;
#define GCC_METHOD3(R, N, A, B, C) const char *cc1_plugin::LANG::N = # N;
#define GCC_METHOD4(R, N, A, B, C, D) const char *cc1_plugin::LANG::N = # N;
#define GCC_METHOD5(R, N, A, B, C, D, E) const char *cc1_plugin::LANG::N = # N;
#define GCC_METHOD7(R, N, A, B, C, D, E, F, G) const char *cc1_plugin::LANG::N = # N;

#define LANG c
#include "gcc-c-fe.def"
#undef LANG

#define LANG cp
#include "gcc-cp-fe.def"
#undef LANG

#undef GCC_METHOD0
#undef GCC_METHOD1
#undef GCC_METHOD2
#undef GCC_METHOD3
#undef GCC_METHOD4
#undef GCC_METHOD5
#undef GCC_METHOD7
