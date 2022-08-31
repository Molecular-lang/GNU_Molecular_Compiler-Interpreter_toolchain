/* Configuration common to all targets running the GNU system.  */

/* Please review: $(src-dir)/SPL-README for Licencing info. */

#undef GNU_USER_TARGET_OS_CPP_BUILTINS
#define GNU_USER_TARGET_OS_CPP_BUILTINS()		\
    do {					\
	builtin_define ("__gnu_hurd__");	\
	builtin_define ("__GNU__");		\
	builtin_define_std ("unix");		\
	builtin_define ("__MACH__");		\
	builtin_assert ("system=gnu");		\
	builtin_assert ("system=mach");		\
	builtin_assert ("system=unix");		\
	builtin_assert ("system=posix");	\
    } while (0)

#define GNU_USER_TARGET_D_OS_VERSIONS()		\
    do {					\
	builtin_version ("Hurd");		\
	builtin_version ("CRuntime_Glibc");	\
    } while (0)
