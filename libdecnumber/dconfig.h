/* Configure decNumber for either host or target. */

#ifdef IN_LIBGCC2

#include "tconfig.h"
#include "coretypes.h"
#include "tm.h"

#if __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
#define WORDS_BIGENDIAN 1
#endif

#else

#include "config.h"

#endif
