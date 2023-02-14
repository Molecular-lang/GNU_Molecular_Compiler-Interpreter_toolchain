/* Configuration common to all targets running RTEMS. */

#ifndef RTEMS_STARTFILE_SPEC
#define RTEMS_STARTFILE_SPEC "crti%O%s crtbegin%O%s"
#endif

#ifndef RTEMS_ENDFILE_SPEC
#define RTEMS_ENDFILE_SPEC "crtend%O%s crtn%O%s"
#endif

/*
 * The crt0.o is a dummy start file to let the linker work as needed by
 * autoconf scripts using this compiler.
 */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{!qrtems:crt0%O%s} " \
"%{qrtems:" RTEMS_STARTFILE_SPEC "}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC \
"%{qrtems:" RTEMS_ENDFILE_SPEC " %{!qnolinkcmds:-T linkcmds%s}}"

/*
 * Some targets do not set up LIB_SPECS, override it, here.
 */
#define STD_LIB_SPEC "%{!shared:%{g*:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}}"

#undef LIB_SPEC
#define LIB_SPEC "%{!qrtems:" STD_LIB_SPEC "} " \
"%{qrtems:--start-group -lrtemsbsp -lrtemscpu -latomic -lc -lgcc --end-group}"

#define TARGET_POSIX_IO

/* Prefer int for int32_t (see stdint-newlib.h).  */
#undef STDINT_LONG32
#define STDINT_LONG32 (INT_TYPE_SIZE != 32 && LONG_TYPE_SIZE == 32)

/* Default to local-exec TLS model.  */
#undef OS_CC1_SPEC
#define OS_CC1_SPEC " %{!ftls-model=*:-ftls-model=local-exec}"
