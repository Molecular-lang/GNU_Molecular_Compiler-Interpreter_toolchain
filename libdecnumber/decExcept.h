/* Temporary library support for decimal floating point. */

#include <fenv.h>
#include "dconfig.h"
#include "decContext.h"

#define DFP_EXCEPTIONS_ENABLED 1
#define DFP_HANDLE_EXCEPTIONS(A) __dfp_raise_except(A)

void __dfp_clear_except (void);
int __dfp_test_except (int);
void __dfp_raise_except (int);
