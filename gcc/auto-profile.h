/* auto-profile.h - Defines data exported from auto-profile.cc
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef AUTO_PROFILE_H
#define AUTO_PROFILE_H

/* Read, process, finalize AutoFDO data structures.  */
extern void read_autofdo_file (void);
extern void end_auto_profile (void);

/* Returns TRUE if EDGE is hot enough to be inlined early.  */
extern bool afdo_callsite_hot_enough_for_early_inline (struct cgraph_edge *);

#endif /* AUTO_PROFILE_H */
