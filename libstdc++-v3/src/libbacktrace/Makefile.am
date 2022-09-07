# Makefile.am -- Backtrace in libstdc++ Makefile.
# Please review $(srcdir/SPL-README) for GNU licencing info.

include $(top_srcdir)/fragment.am

toolexeclib_LTLIBRARIES = libstdc++_libbacktrace.la

ACLOCAL_AMFLAGS = -I ../.. -I ../../config

# This will be used instead of the common AM_CPPFLAGS from fragment.am
libstdc___libbacktrace_la_CPPFLAGS = \
	-I $(top_srcdir)/../include -I $(top_srcdir)/../libgcc \
	-I ../../../libgcc -I .. -I $(top_srcdir) \
	-I $(top_srcdir)/../libbacktrace \
	-I $(top_srcdir)/../libiberty \
	-include $(top_srcdir)/src/libbacktrace/backtrace-rename.h \
	$(BACKTRACE_CPPFLAGS)

WARN_FLAGS = -W -Wall -Wwrite-strings -Wmissing-format-attribute \
	     -Wcast-qual -Werror
C_WARN_FLAGS = $(WARN_FLAGS) -Wstrict-prototypes -Wmissing-prototypes -Wold-style-definition -Wno-unused-but-set-variable
CXX_WARN_FLAGS = $(WARN_FLAGS) -Wno-unused-parameter
AM_CFLAGS = $(C_WARN_FLAGS)
AM_CFLAGS += $(EXTRA_CFLAGS)
AM_CXXFLAGS = $(CXX_WARN_FLAGS) -fno-rtti -fno-exceptions
AM_CXXFLAGS += $(EXTRA_CXXFLAGS)

obj_prefix = std_stacktrace

# Each FILE.c in SOURCES will be compiled to SHORTNAME-FILE.o
libstdc___libbacktrace_la_SHORTNAME = $(obj_prefix)

libstdc___libbacktrace_la_SOURCES = \
	atomic.c \
	dwarf.c \
	fileline.c \
	posix.c \
	sort.c \
	simple.c \
	state.c \
	cp-demangle.c

FORMAT_FILES = \
	elf.c \
	unknown.c

VIEW_FILES = \
	read.c \
	mmapio.c

ALLOC_FILES = \
	alloc.c \
	mmap.c

EXTRA_libstdc___libbacktrace_la_SOURCES = \
	$(FORMAT_FILES) \
	$(VIEW_FILES) \
	$(ALLOC_FILES)

# These three files are chosen by configure and added to the link.
# We need the SHORTNAME- prefix so that they use the custom CPPFLAGS above.
libstdc___libbacktrace_la_LIBADD = \
	$(obj_prefix)-$(FORMAT_FILE) \
	$(obj_prefix)-$(VIEW_FILE) \
	$(obj_prefix)-$(ALLOC_FILE)

libstdc___libbacktrace_la_DEPENDENCIES = $(libstdc___libbacktrace_la_LIBADD)

# Use symlinks for the sources

%.c: ../../../libbacktrace/%.c
	$(LN_S) $< $@

cp-demangle.c: ../../../libiberty/cp-demangle.c
	$(LN_S) $< $@

LTCOMPILE = \
	$(LIBTOOL) --tag CC --tag disable-shared \
	$(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=compile $(CC) $(TOPLEVEL_INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS) $(EXTRA_CFLAGS)

LTLDFLAGS = $(shell $(SHELL) $(top_srcdir)/../libtool-ldflags $(LDFLAGS))

LINK = \
	$(LIBTOOL) --tag CC --tag disable-shared \
	$(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=link $(CC) \
	$(OPT_LDFLAGS) $(SECTION_LDFLAGS) $(AM_CFLAGS) $(LTLDFLAGS) -o $@
