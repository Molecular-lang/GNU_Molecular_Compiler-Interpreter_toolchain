/* crtend object for windows32 targets. */

/* Target machine header files require this define. */
#define IN_LIBGCC2

/* auto-host.h is needed by cygming.h for HAVE_GAS_WEAK and here
   for HAVE_LD_RO_RW_SECTION_MIXING.  */  
#include "auto-host.h"
#include "tconfig.h"
#include "tsystem.h"
#include "coretypes.h"
#include "tm.h"
#include "libgcc_tm.h"
#include "unwind-dw2-fde.h"

#if defined(HAVE_LD_RO_RW_SECTION_MIXING)
# define EH_FRAME_SECTION_CONST const
#else
# define EH_FRAME_SECTION_CONST
#endif

#if DWARF2_UNWIND_INFO
/* Terminate the frame unwind info section with a 0 as a sentinel;
   this would be the 'length' field in a real FDE.  */

static EH_FRAME_SECTION_CONST int __FRAME_END__[]
  __attribute__ ((used,  section(__LIBGCC_EH_FRAME_SECTION_NAME__),
		  aligned(4)))
  = { 0 };
#endif

extern void __gcc_register_frame (void); 
extern void __gcc_deregister_frame (void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wprio-ctor-dtor"
static void register_frame_ctor (void) __attribute__ ((constructor (0)));
#pragma GCC diagnostic pop

static void
register_frame_ctor (void)
{
  __gcc_register_frame ();
}

#if !DEFAULT_USE_CXA_ATEXIT
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wprio-ctor-dtor"
static void deregister_frame_dtor (void) __attribute__ ((destructor (0)));
#pragma GCC diagnostic pop

static void
deregister_frame_dtor (void)
{
  __gcc_deregister_frame ();
}
#endif
