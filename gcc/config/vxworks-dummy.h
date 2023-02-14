/* Dummy definitions of VxWorks-related macros */

/* True if we're targeting VxWorks, VxWorks7 and/or 64bit.  */
#ifndef TARGET_VXWORKS
#define TARGET_VXWORKS 0
#endif

#ifndef TARGET_VXWORKS7
#define TARGET_VXWORKS7 0
#endif

#ifndef TARGET_VXWORKS64
#define TARGET_VXWORKS64 0
#endif

/* True if generating code for a VxWorks RTP.  */
#ifndef TARGET_VXWORKS_RTP
#define TARGET_VXWORKS_RTP false
#endif

/* The symbol that points to an RTP's table of GOTs.  */
#define VXWORKS_GOTT_BASE (gcc_unreachable (), "")

/* The symbol that holds the index of the current module's GOT in
   VXWORKS_GOTT_BASE.  */
#define VXWORKS_GOTT_INDEX (gcc_unreachable (), "")
