/* Definitions for the D front end on the x86 architecture. */

/* In i386-d.cc  */
extern void ix86_d_target_versions (void);
extern void ix86_d_register_target_info (void);
extern bool ix86_d_has_stdcall_convention (unsigned int *, unsigned int *);

/* Target hooks for D language.  */
#define TARGET_D_CPU_VERSIONS ix86_d_target_versions
#define TARGET_D_REGISTER_CPU_TARGET_INFO ix86_d_register_target_info
#define TARGET_D_HAS_STDCALL_CONVENTION ix86_d_has_stdcall_convention
