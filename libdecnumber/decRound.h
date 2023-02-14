/* Internal testing support for rounding for decimal float. */

#include "decContext.h"

#define DFP_INIT_ROUNDMODE(A)  A = __decGetRound()

extern void __dfp_set_round (int);
extern int __dfp_get_round (void);
extern enum rounding __decGetRound (void);
