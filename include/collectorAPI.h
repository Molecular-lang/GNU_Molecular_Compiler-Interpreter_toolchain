#ifndef _COLLECTORAPI_H
#define _COLLECTORAPI_H

/* This file contains function prototypes for the user-callable API
   routines in libcollector.  */

#include <pthread.h>

#ifdef __cplusplus
extern "C"
{
#endif
  /* Routine to record a sample in the experiment.  */
  extern void collector_sample (const char *name);

  /* Routine to suspend data collection during an experiment.  */
  extern void collector_pause (void);

  /* Routine to resume data collection during an experiment.  */
  extern void collector_resume (void);

  /* Routine to suspend per-thread data collection during an experiment.  */
  extern void collector_thread_pause (pthread_t tid);

  /* Routine to resume per-thread data collection during an experiment.  */
  extern void collector_thread_resume (pthread_t tid);

  /* Routine to close the experiment, and stop all data collection.  */
  extern void  collector_terminate_expt (void);

  typedef struct
  {
    unsigned int offset;
    unsigned int lineno;
  } Lineno;

  /* Routines to let libcollector know about dynamically loaded functions.  */
  extern void collector_func_load (const char *name, const char *alias,
				   const char *sourcename, void *vaddr,
				   int size, int lntsize, Lineno *lntable);

  extern void collector_func_unload (void *vaddr);

#ifdef NEED_COLLECTOR_MODULE
  extern void collector_module_load (const char *modulename, void *vaddr);
  extern void collector_module_unload (void *vaddr);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _COLLECTORAPI_H */
