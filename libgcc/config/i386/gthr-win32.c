/* Implementation of threads compatibility routines for libgcc2.  */

/* Get the out-of-line version of the inline routines.  */

#define __GTHREAD_WIN32_ACTIVE_P() 1
#define __GTHREAD_WIN32_INLINE

#define __gthread_detach __gthr_win32_detach
#define __gthread_equal __gthr_win32_equal
#define __gthread_yield __gthr_win32_yield
#define __gthread_once __gthr_win32_once
#define __gthread_key_create __gthr_win32_key_create
#define __gthread_key_delete __gthr_win32_key_delete
#define __gthread_getspecific __gthr_win32_getspecific
#define __gthread_setspecific __gthr_win32_setspecific
#define __gthread_mutex_init_function __gthr_win32_mutex_init_function
#define __gthread_mutex_destroy __gthr_win32_mutex_destroy
#define __gthread_mutex_lock __gthr_win32_mutex_lock
#define __gthread_mutex_trylock __gthr_win32_mutex_trylock
#define __gthread_mutex_unlock __gthr_win32_mutex_unlock
#define __gthread_recursive_mutex_trylock __gthr_win32_recursive_mutex_trylock

#include "gthr-win32.h"

/* Check the sizes of the local version of the Win32 types.  */

#define CHECK_SIZE_OF(TYPE) \
  typedef int assertion[sizeof(__gthr_win32_##TYPE) == sizeof(TYPE) ? 1 : -1];

CHECK_SIZE_OF (DWORD)
CHECK_SIZE_OF (HANDLE)
CHECK_SIZE_OF (CRITICAL_SECTION)
