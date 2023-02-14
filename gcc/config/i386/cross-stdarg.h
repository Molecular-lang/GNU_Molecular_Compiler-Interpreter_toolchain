#ifndef __CROSS_STDARG_H_INCLUDED
#define __CROSS_STDARG_H_INCLUDED

/* Make sure that for non x64 targets cross builtins are defined.  */
#ifndef __x86_64__
/* Call abi ms_abi.  */
#define __builtin_ms_va_list __builtin_va_list
#define __builtin_ms_va_copy __builtin_va_copy
#define __builtin_ms_va_start __builtin_va_start
#define __builtin_ms_va_end __builtin_va_end

/* Call abi sysv_abi.  */
#define __builtin_sysv_va_list __builtin_va_list
#define __builtin_sysv_va_copy __builtin_va_copy
#define __builtin_sysv_va_start __builtin_va_start
#define __builtin_sysv_va_end __builtin_va_end
#endif

#define __ms_va_copy(__d,__s) __builtin_ms_va_copy(__d,__s)
#define __ms_va_start(__v,__l) __builtin_ms_va_start(__v,__l)
#define __ms_va_arg(__v,__l)	__builtin_va_arg(__v,__l)
#define __ms_va_end(__v) __builtin_ms_va_end(__v)

#define __sysv_va_copy(__d,__s) __builtin_sysv_va_copy(__d,__s)
#define __sysv_va_start(__v,__l) __builtin_sysv_va_start(__v,__l)
#define __sysv_va_arg(__v,__l)	__builtin_va_arg(__v,__l)
#define __sysv_va_end(__v) __builtin_sysv_va_end(__v)

#ifndef __GNUC_SYSV_VA_LIST
#define __GNUC_SYSV_VA_LIST
  typedef __builtin_sysv_va_list __gnuc_sysv_va_list;
#endif

#ifndef _SYSV_VA_LIST_DEFINED
#define _SYSV_VA_LIST_DEFINED
  typedef __gnuc_sysv_va_list sysv_va_list;
#endif

#ifndef __GNUC_MS_VA_LIST
#define __GNUC_MS_VA_LIST
  typedef __builtin_ms_va_list __gnuc_ms_va_list;
#endif

#ifndef _MS_VA_LIST_DEFINED
#define _MS_VA_LIST_DEFINED
  typedef __gnuc_ms_va_list ms_va_list;
#endif

#endif /* __CROSS_STDARG_H_INCLUDED */
