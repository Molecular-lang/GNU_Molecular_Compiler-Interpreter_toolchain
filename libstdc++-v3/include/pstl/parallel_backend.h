#ifndef _PSTL_PARALLEL_BACKEND_H
#define _PSTL_PARALLEL_BACKEND_H

#if defined(_PSTL_PAR_BACKEND_SERIAL)
#    include "parallel_backend_serial.h"
namespace __pstl
{
namespace __par_backend = __serial_backend;
}
#elif defined(_PSTL_PAR_BACKEND_TBB)
#    include "parallel_backend_tbb.h"
namespace __pstl
{
namespace __par_backend = __tbb_backend;
}
#else
_PSTL_PRAGMA_MESSAGE("Parallel backend was not specified");
#endif

#endif /* _PSTL_PARALLEL_BACKEND_H */
