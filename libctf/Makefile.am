## Process this file with automake to produce Makefile.in.
#
#

ACLOCAL_AMFLAGS = -I .. -I ../config -I ../bfd

AUTOMAKE_OPTIONS = dejagnu foreign info-in-builddir no-texinfo.tex

# Variables that we might accumulate conditionally or in subdirs.
info_TEXINFOS =
DISTCLEANFILES =
MAINTAINERCLEANFILES =

# This is where we get zlib from.  zlibdir is -L../zlib and zlibinc is
# -I../zlib, unless we were configured with --with-system-zlib, in which
# case both are empty.
ZLIB = @zlibdir@ -lz
ZLIBINC = @zlibinc@

BASEDIR = $(srcdir)/..
BFDDIR = $(BASEDIR)/bfd
INCDIR = $(srcdir)/../include
AM_CPPFLAGS = -D_GNU_SOURCE -I$(srcdir) -I$(srcdir)/../include -I$(srcdir)/../bfd -I../bfd @INCINTL@
AM_CFLAGS = -std=gnu99 @ac_libctf_warn_cflags@ @warn@ @c_warn@ @WARN_PEDANTIC@ @WERROR@ $(ZLIBINC)

if INSTALL_LIBBFD
lib_LTLIBRARIES = libctf.la libctf-nobfd.la
include_HEADERS = $(INCDIR)/ctf.h $(INCDIR)/ctf-api.h
else
include_HEADERS =
noinst_LTLIBRARIES = libctf.la libctf-nobfd.la
endif

libctf_nobfd_la_LIBADD = @CTF_LIBADD@ $(ZLIB)
libctf_ldflags_nover = -version-info 0:0:0 @SHARED_LDFLAGS@
libctf_nobfd_la_LDFLAGS = $(libctf_ldflags_nover) @VERSION_FLAGS_NOBFD@
libctf_nobfd_la_CPPFLAGS = $(AM_CPPFLAGS) -DNOBFD=1
libctf_nobfd_la_SOURCES = ctf-archive.c ctf-dump.c ctf-create.c ctf-decl.c ctf-error.c \
			  ctf-hash.c ctf-labels.c ctf-dedup.c ctf-link.c ctf-lookup.c \
			  ctf-open.c ctf-serialize.c ctf-sha1.c ctf-string.c ctf-subr.c \
			  ctf-types.c ctf-util.c
if NEED_CTF_QSORT_R
libctf_nobfd_la_SOURCES += ctf-qsort_r.c
endif

# @CTF_LIBADD@ appears here twice: once, to force libiberty to get searched before
# install-time libbfd adds a -L to the install dir (possibly pointing at an
# incompatible libiberty), and once via lictf_nobfd_la_LIBADD so that the
# references in there get picked up.
libctf_la_LIBADD =  @CTF_LIBADD@ ../bfd/libbfd.la $(libctf_nobfd_la_LIBADD)
libctf_la_CPPFLAGS = $(AM_CPPFLAGS) -DNOBFD=0
libctf_la_LDFLAGS = $(libctf_ldflags_nover) @VERSION_FLAGS@
libctf_la_SOURCES = $(libctf_nobfd_la_SOURCES) ctf-open-bfd.c

# Setup the testing framework, if you have one
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

if TCL_TRY
CC_FOR_TARGET = ` \
  if [ -f $$r/../gcc/xgcc ] ; then \
    if [ -f $$r/../newlib/Makefile ] ; then \
      echo $$r/../gcc/xgcc -B$$r/../gcc/ -idirafter $$r/../newlib/targ-include -idirafter $${srcroot}/../newlib/libc/include -nostdinc; \
    else \
      echo $$r/../gcc/xgcc -B$$r/../gcc/; \
    fi; \
  else \
    if [ "@host@" = "@target@" ] ; then \
      echo $(CC); \
    else \
      echo gcc | sed '$(transform)'; \
    fi; \
  fi`

check-DEJAGNU:

development.exp:

# development.sh is used to determine -Werror default.
CONFIG_STATUS_DEPENDENCIES = $(BFDDIR)/development.sh

EXTRA_DEJAGNU_SITE_CONFIG = development.exp

DISTCLEANFILES += site.exp development.exp
endif
