## Process this file with automake to generate Makefile.in
#

AUTOMAKE_OPTIONS = foreign no-dist
ACLOCAL_AMFLAGS = -I .. -I ../config -I ../bfd

# Build '.' first so all generated files exist.
SUBDIRS = .

INCDIR = $(srcdir)/../include
BFDDIR = $(srcdir)/../bfd

WARN_CFLAGS = @WARN_CFLAGS@
NO_WERROR = @NO_WERROR@
AM_CFLAGS = $(WARN_CFLAGS)

COMPILE_FOR_BUILD = $(CC_FOR_BUILD) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CFLAGS_FOR_BUILD)
LINK_FOR_BUILD = $(CC_FOR_BUILD) $(CFLAGS_FOR_BUILD) \
	$(LDFLAGS_FOR_BUILD) -o $@

libopcodes_la_LDFLAGS =
if INSTALL_LIBBFD
bfdlibdir = @bfdlibdir@
bfdincludedir = @bfdincludedir@
bfdlib_LTLIBRARIES = libopcodes.la
bfdinclude_DATA = $(INCDIR)/dis-asm.h
else
# Empty these so that the respective installation directories will not be created.
bfdlibdir =
bfdincludedir =
rpath_bfdlibdir = @bfdlibdir@
noinst_LTLIBRARIES = libopcodes.la
libopcodes_la_LDFLAGS += -rpath $(rpath_bfdlibdir)
endif

# This is where bfd.h lives.
BFD_H = ../bfd/bfd.h

BUILD_LIBS = @BUILD_LIBS@
BUILD_LIB_DEPS = @BUILD_LIB_DEPS@

# Header files.
HFILES = \
	aarch64-asm.h aarch64-dis.h aarch64-opc.h aarch64-tbl.h \
	bpf-desc.h bpf-opc.h \
	cris-desc.h cris-opc.h \
	epiphany-desc.h epiphany-opc.h \
	fr30-desc.h fr30-opc.h \
	frv-desc.h frv-opc.h \
	i386-init.h \
	i386-opc.h \
	i386-tbl.h \
	ia64-asmtab.h \
	ia64-opc.h \
	ip2k-desc.h ip2k-opc.h \
	iq2000-desc.h iq2000-opc.h \
	lm32-desc.h \
	lm32-opc.h \
	m32c-desc.h m32c-opc.h \
	m32r-desc.h m32r-opc.h \
	mcore-opc.h \
	mep-desc.h mep-opc.h \
	microblaze-opc.h \
	mt-desc.h mt-opc.h \
	score-opc.h \
	sh-opc.h \
	sysdep.h \
	xstormy16-desc.h xstormy16-opc.h \
	z8k-opc.h

# C source files that correspond to .o's ending up in libopcodes
# for all machines.
TARGET64_LIBOPCODES_CFILES = \
	aarch64-asm.co \
	aarch64-asm-2.co \
	aarch64-dis.co \
	aarch64-dis-2.co \
	aarch64-opc.co \
	aarch64-opc-2.co \
	alpha-dis.co \
	alpha-opc.co \
	bpf-asm.co \
	bpf-desc.co \
	bpf-dis.co \
	bpf-ibld.co \
	bpf-opc.co \
	ia64-dis.co \
	ia64-opc.co \
	loongarch-opc.co \
	loongarch-dis.co \
	loongarch-coder.co \
	mips-dis.co \
	mips-opc.co \
	mips16-opc.co \
	micromips-opc.co \
	mmix-dis.co \
	mmix-opc.co \
	nfp-dis.co \
	riscv-dis.co \
	riscv-opc.co \
	tilegx-dis.co \
	tilegx-opc.co

TARGET32_LIBOPCODES_CFILES = \
	arc-dis.co \
	arc-ext.co \
	arc-opc.co \
	arm-dis.co \
	avr-dis.co \
	bfin-dis.co \
	cgen-asm.co \
	cgen-bitset.co \
	cgen-dis.co \
	cgen-opc.co \
	cr16-dis.co \
	cr16-opc.co \
	cris-desc.co \
	cris-dis.co \
	cris-opc.co \
	crx-dis.co \
	crx-opc.co \
	csky-dis.co \
	d10v-dis.co \
	d10v-opc.co \
	d30v-dis.co \
	d30v-opc.co \
	dlx-dis.co \
	epiphany-asm.co \
	epiphany-desc.co \
	epiphany-dis.co \
	epiphany-ibld.co \
	epiphany-opc.co \
	fr30-asm.co \
	fr30-desc.co \
	fr30-dis.co \
	fr30-ibld.co \
	fr30-opc.co \
	frv-asm.co \
	frv-desc.co \
	frv-dis.co \
	frv-ibld.co \
	frv-opc.co \
	ft32-dis.co \
	ft32-opc.co \
	h8300-dis.co \
	hppa-dis.co \
	i386-dis.co \
	i386-opc.co \
	ip2k-asm.co \
	ip2k-desc.co \
	ip2k-dis.co \
	ip2k-ibld.co \
	ip2k-opc.co \
	iq2000-asm.co \
	iq2000-desc.co \
	iq2000-dis.co \
	iq2000-ibld.co \
	iq2000-opc.co \
	lm32-asm.co \
	lm32-desc.co \
	lm32-dis.co \
	lm32-ibld.co \
	lm32-opc.co \
	lm32-opinst.co \
	m10200-dis.co \
	m10200-opc.co \
	m10300-dis.co \
	m10300-opc.co \
	m32c-asm.co \
	m32c-desc.co \
	m32c-dis.co \
	m32c-ibld.co \
	m32c-opc.co \
	m32r-asm.co \
	m32r-desc.co \
	m32r-dis.co \
	m32r-ibld.co \
	m32r-opc.co \
	m32r-opinst.co \
	m68hc11-dis.co \
	m68hc11-opc.co \
	m68k-dis.co \
	m68k-opc.co \
	s12z-dis.co \
	s12z-opc.co \
	mcore-dis.co \
	mep-asm.co \
	mep-desc.co \
	mep-dis.co \
	mep-ibld.co \
	mep-opc.co \
	metag-dis.co \
	microblaze-dis.co \
	moxie-dis.co \
	moxie-opc.co \
	msp430-decode.co \
	msp430-dis.co \
	mt-asm.co \
	mt-desc.co \
	mt-dis.co \
	mt-ibld.co \
	mt-opc.co \
	nds32-asm.co \
	nds32-dis.co \
	nios2-dis.co \
	nios2-opc.co \
	ns32k-dis.co \
	or1k-asm.co \
	or1k-desc.co \
	or1k-dis.co \
	or1k-ibld.co \
	or1k-opc.co \
	pdp11-dis.co \
	pdp11-opc.co \
	pj-dis.co \
	pj-opc.co \
	ppc-dis.co \
	ppc-opc.co \
	pru-dis.co \
	pru-opc.co \
	rl78-decode.co \
	rl78-dis.co \
	rx-decode.co \
	rx-dis.co \
	s390-dis.co \
	s390-opc.co \
	score-dis.co \
	score7-dis.co \
	sh-dis.co \
	sparc-dis.co \
	sparc-opc.co \
	spu-dis.co \
	spu-opc.co \
	tic30-dis.co \
	tic4x-dis.co \
	tic54x-dis.co \
	tic54x-opc.co \
	tic6x-dis.co \
	tilepro-dis.co \
	tilepro-opc.co \
	v850-dis.co \
	v850-opc.co \
	vax-dis.co \
	visium-dis.co \
	visium-opc.co \
	wasm32-dis.co \
	xstormy16-asm.co \
	xstormy16-desc.co \
	xstormy16-dis.co \
	xstormy16-ibld.co \
	xstormy16-opc.co \
	xtensa-dis.co \
	xgate-dis.co \
	xgate-opc.co \
	z80-dis.co \
	z8k-dis.co

# C source files that correspond to .o's ending up in libopcodes.
LIBOPCODES_CFILES = \
	$(TARGET32_LIBOPCODES_CFILES) \
	$(TARGET64_LIBOPCODES_CFILES) \
	dis-buf.co \
	dis-init.co \
	disassemble.co

# C source files that correspond to .o's.
CFILES = \
	$(LIBOPCODES_CFILES) \
	aarch64-gen.co \
	i386-gen.co \
	ia64-asmtab.co \
	ia64-gen.co \
	ia64-opc-a.co \
	ia64-opc-b.co \
	ia64-opc-f.co \
	ia64-opc-i.co \
	ia64-opc-m.co \
	ia64-opc-d.co \
	s390-mkopc.co \
	z8kgen.co

ALL32_MACHINES = $(TARGET32_LIBOPCODES_CFILES:.co=.lo)
ALL64_MACHINES = $(TARGET64_LIBOPCODES_CFILES:.co=.lo)

OFILES = @BFD_MACHINES@

# development.sh is used to determine -Werror default.
CONFIG_STATUS_DEPENDENCIES = $(BFDDIR)/development.sh

AM_CPPFLAGS = -I. -I$(srcdir) -I../bfd -I$(INCDIR) -I$(BFDDIR) @HDEFINES@ @INCINTL@

disassemble.lo: disassemble.co
if am__fastdepCC
	$(AM_V_CC)$(LTCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ @archdefs@ $(srcdir)/disassemble.co
	$(AM_V_at)mv -f $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
else
if AMDEP
	source='disassemble.co' object='$@' libtool=yes @AMDEPBACKSLASH@
	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) @AMDEPBACKSLASH@
endif
	$(AM_V_CC)$(LTCOMPILE) -c -o $@ @archdefs@ $(srcdir)/disassemble.co
endif

libopcodes_la_SOURCES =  dis-buf.co disassemble.co dis-init.co
libopcodes_la_DEPENDENCIES = $(OFILES) @SHARED_DEPENDENCIES@
libopcodes_la_LIBADD = $(OFILES) @SHARED_LIBADD@
libopcodes_la_LDFLAGS += -release `cat ../bfd/libtool-soversion` @SHARED_LDFLAGS@
# Allow dependency tracking to work on all the source files.
EXTRA_libopcodes_la_SOURCES = $(LIBOPCODES_CFILES)

# libtool will build .libs/libopcodes.a.  We create libopcodes.a in
# the build directory so that we don't have to convert all the
# programs that use libopcodes.a simultaneously.  This is a hack which
# should be removed if everything else starts using libtool.  FIXME.

noinst_LIBRARIES = libopcodes.a
libopcodes_a_SOURCES =

stamp-lib: libopcodes.la
	libtooldir=`$(LIBTOOL) --config | sed -n -e 's/^objdir=//p'`; \
	if [ -f $$libtooldir/libopcodes.a ]; then \
	  cp $$libtooldir/libopcodes.a libopcodes.tmp; \
	  $(RANLIB) libopcodes.tmp; \
	  $(SHELL) $(srcdir)/../move-if-change libopcodes.tmp libopcodes.a; \
	else true; fi
	touch stamp-lib

libopcodes.a: stamp-lib ; @true

POTFILES = $(HFILES) $(CFILES)
po/POTFILES.in: @MAINT@ Makefile
	for f in $(POTFILES); do echo $$f; done | LC_ALL=C sort > tmp \
	  && mv tmp $(srcdir)/po/POTFILES.in

CLEANFILES = \
	stamp-epiphany stamp-fr30 stamp-frv stamp-ip2k stamp-iq2000 stamp-lm32 \
	stamp-m32c stamp-m32r stamp-mep stamp-mt stamp-or1k stamp-xstormy16 \
	libopcodes.a stamp-lib


CGENDIR = @cgendir@
CPUDIR = $(srcdir)/../cpu
GUILE = `if test -f ../guile/libguile/guile ; then echo ../guile/libguile/guile; else echo guile ; fi`
CGEN = "$(GUILE) -l ${cgendir}/guile.scm -s"
CGENFLAGS = -v

CGENDEPS = \
	$(CGENDIR)/desc.scm $(CGENDIR)/desc-cpu.scm \
	$(CGENDIR)/opcodes.scm $(CGENDIR)/opc-asmdis.scm \
	$(CGENDIR)/opc-ibld.scm $(CGENDIR)/opc-itab.scm \
	$(CGENDIR)/opc-opinst.scm \
	cgen-asm.in cgen-dis.in cgen-ibld.in

CGEN_CPUS = cris epiphany fr30 frv ip2k iq2000 lm32 m32c m32r mep mt or1k xstormy16

if CGEN_MAINT
BPF_DEPS = stamp-bpf
CRIS_DEPS = stamp-cris
EPIPHANY_DEPS = stamp-epiphany
FR30_DEPS = stamp-fr30
FRV_DEPS = stamp-frv
IP2K_DEPS = stamp-ip2k
IQ2000_DEPS = stamp-iq2000
LM32_DEPS = stamp-lm32
M32C_DEPS = stamp-m32c
M32R_DEPS = stamp-m32r
MEP_DEPS = stamp-mep
MT_DEPS = stamp-mt
OR1K_DEPS = stamp-or1k
XSTORMY16_DEPS = stamp-xstormy16
else
BPF_DEPS =
CRIS_DEPS =
EPIPHANY_DEPS =
FR30_DEPS =
FRV_DEPS =
IP2K_DEPS =
IQ2000_DEPS =
LM32_DEPS =
M32C_DEPS =
M32R_DEPS =
MEP_DEPS =
MT_DEPS =
OR1K_DEPS =
XSTORMY16_DEPS =
endif

run-cgen:
	$(SHELL) $(srcdir)/cgen.sh opcodes $(srcdir) $(CGEN) \
	  $(CGENDIR) "$(CGENFLAGS)" $(arch) $(prefix) $(archfile) $(opcfile) \
	  "$(options)" "$(extrafiles)"
	touch stamp-${prefix}
.PHONY: run-cgen

# Maintainer utility rule to regenerate all cgen files.
run-cgen-all:
	for c in $(CGEN_CPUS) ; \
	do \
		$(MAKE) stamp-$$c || exit 1 ; \
	done
.PHONY: run-cgen-all

# For now, require developers to configure with --enable-cgen-maint.

$(srcdir)/bpf-desc.h $(srcdir)/bpf-desc.co $(srcdir)/bpf-opc.h \
		$(srcdir)/bpf-opc.co $(srcdir)/bpf-ibld.co \
		$(srcdir)/bpf-asm.co $(srcdir)/bpf-dis.co: $(BPF_DEPS)
	@true

stamp-bpf: $(CGENDEPS) $(CPUDIR)/bpf.cpu $(CPUDIR)/bpf.opc
	$(MAKE) run-cgen arch=bpf prefix=bpf \
		archfile=$(CPUDIR)/bpf.cpu opcfile=$(CPUDIR)/bpf.opc

$(srcdir)/cris-desc.h $(srcdir)/cris-desc.co $(srcdir)/cris-opc.h: $(CRIS_DEPS)
	@true

stamp-cris: $(CGENDEPS) $(CPUDIR)/cris.cpu
	$(SHELL) $(srcdir)/cgen.sh desc $(srcdir) $(CGEN) \
	  $(CGENDIR) "$(CGENFLAGS)" cris cris $(CPUDIR)/cris.cpu /dev/null \
	  "$(options)" "$(extrafiles)"
	touch $@

$(srcdir)/epiphany-desc.h $(srcdir)/epiphany-desc.co $(srcdir)/epiphany-opc.h \
		$(srcdir)/epiphany-opc.co $(srcdir)/epiphany-ibld.co \
		$(srcdir)/epiphany-opinst.co $(srcdir)/epiphany-asm.co \
		$(srcdir)/epiphany-dis.co: $(EPIPHANY_DEPS)
	@true

stamp-epiphany: $(CGENDEPS) $(CPUDIR)/epiphany.cpu $(CPUDIR)/epiphany.opc
	$(MAKE) run-cgen arch=epiphany prefix=epiphany options= \
		archfile=$(CPUDIR)/epiphany.cpu opcfile=$(CPUDIR)/epiphany.opc extrafiles=

$(srcdir)/fr30-desc.h $(srcdir)/fr30-desc.co $(srcdir)/fr30-opc.h $(srcdir)/fr30-opc.co $(srcdir)/fr30-ibld.co $(srcdir)/fr30-asm.co $(srcdir)/fr30-dis.co: $(FR30_DEPS)
	@true
stamp-fr30: $(CGENDEPS) $(CPUDIR)/fr30.cpu $(CPUDIR)/fr30.opc
	$(MAKE) run-cgen arch=fr30 prefix=fr30 options= \
		archfile=$(CPUDIR)/fr30.cpu opcfile=$(CPUDIR)/fr30.opc extrafiles=

$(srcdir)/frv-desc.h $(srcdir)/frv-desc.co $(srcdir)/frv-opc.h $(srcdir)/frv-opc.co $(srcdir)/frv-ibld.co $(srcdir)/frv-asm.co $(srcdir)/frv-dis.co: $(FRV_DEPS)
	@true
stamp-frv: $(CGENDEPS) $(CPUDIR)/frv.cpu $(CPUDIR)/frv.opc
	$(MAKE) run-cgen arch=frv prefix=frv options= \
		archfile=$(CPUDIR)/frv.cpu opcfile=$(CPUDIR)/frv.opc extrafiles=

$(srcdir)/ip2k-desc.h $(srcdir)/ip2k-desc.co $(srcdir)/ip2k-opc.h $(srcdir)/ip2k-opc.co $(srcdir)/ip2k-ibld.co $(srcdir)/ip2k-asm.co $(srcdir)/ip2k-dis.co: $(IP2K_DEPS)
	@true
stamp-ip2k: $(CGENDEPS) $(CPUDIR)/ip2k.cpu $(CPUDIR)/ip2k.opc
	$(MAKE) run-cgen arch=ip2k prefix=ip2k options= \
		archfile=$(CPUDIR)/ip2k.cpu opcfile=$(CPUDIR)/ip2k.opc extrafiles=

$(srcdir)/iq2000-desc.h $(srcdir)/iq2000-desc.co $(srcdir)/iq2000-opc.h $(srcdir)/iq2000-opc.co $(srcdir)/iq2000-ibld.co $(srcdir)/iq2000-asm.co $(srcdir)/iq2000-dis.co: $(IQ2000_DEPS)
	@true
stamp-iq2000: $(CGENDEPS) $(CPUDIR)/iq2000.cpu \
		$(CPUDIR)/iq2000.opc $(CPUDIR)/iq2000m.cpu \
		$(CPUDIR)/iq10.cpu
	$(MAKE) run-cgen arch=iq2000 prefix=iq2000 options= \
		archfile=$(CPUDIR)/iq2000.cpu \
		opcfile=$(CPUDIR)/iq2000.opc extrafiles=

$(srcdir)lm32-desc.h $(srcdir)/lm32-desc.co $(srcdir)/lm32-opc.h $(srcdir)/lm32-opc.co $(srcdir)/lm32-ibld.co $(srcdir)/lm32-opinst.co $(srcdir)/lm32-asm.co $(srcdir)/lm32-dis.co: $(LM32_DEPS)
	@true
stamp-lm32: $(CGENDEPS) $(CPUDIR)/lm32.cpu $(CPUDIR)/lm32.opc
	$(MAKE) run-cgen arch=lm32 prefix=lm32 options=opinst \
		archfile=$(CPUDIR)/lm32.cpu \
		opcfile=$(CPUDIR)/lm32.opc \
		extrafiles=opinst

$(srcdir)/m32c-desc.h $(srcdir)/m32c-desc.co $(srcdir)/m32c-opc.h $(srcdir)/m32c-opc.co $(srcdir)/m32c-ibld.co $(srcdir)/m32c-asm.co $(srcdir)/m32c-dis.co: $(M32C_DEPS)
	@true
stamp-m32c: $(CGENDEPS) $(CPUDIR)/m32c.cpu $(CPUDIR)/m32c.opc
	$(MAKE) run-cgen arch=m32c prefix=m32c options= \
		archfile=$(CPUDIR)/m32c.cpu \
		opcfile=$(CPUDIR)/m32c.opc extrafiles=

$(srcdir)/m32r-desc.h $(srcdir)/m32r-desc.co $(srcdir)/m32r-opc.h $(srcdir)/m32r-opc.co $(srcdir)/m32r-ibld.co $(srcdir)/m32r-opinst.co $(srcdir)/m32r-asm.co $(srcdir)/m32r-dis.co: $(M32R_DEPS)
	@true
stamp-m32r: $(CGENDEPS) $(CPUDIR)/m32r.cpu $(CPUDIR)/m32r.opc
	$(MAKE) run-cgen arch=m32r prefix=m32r options=opinst \
		archfile=$(CPUDIR)/m32r.cpu \
		opcfile=$(CPUDIR)/m32r.opc extrafiles=opinst

$(srcdir)/mep-desc.h $(srcdir)/mep-desc.co $(srcdir)/mep-opc.h $(srcdir)/mep-opc.co $(srcdir)/mep-ibld.co $(srcdir)/mep-asm.co $(srcdir)/mep-dis.co: $(MEP_DEPS)
	@true
stamp-mep: $(CGENDEPS) $(CPUDIR)/mep.cpu $(CPUDIR)/mep-default.cpu $(CPUDIR)/mep-core.cpu $(CPUDIR)/mep-h1.cpu $(CPUDIR)/mep-ext-cop.cpu $(CPUDIR)/mep-sample-ucidsp.cpu $(CPUDIR)/mep-rhcop.cpu $(CPUDIR)/mep-fmax.cpu $(CPUDIR)/mep.opc
	$(MAKE) run-cgen arch=mep prefix=mep options= \
		archfile=$(CPUDIR)/mep.cpu opcfile=$(CPUDIR)/mep.opc extrafiles=

$(srcdir)/mt-desc.h $(srcdir)/mt-desc.co $(srcdir)/mt-opc.h $(srcdir)/mt-opc.co $(srcdir)/mt-ibld.co $(srcdir)/mt-asm.co $(srcdir)/mt-dis.co: $(MT_DEPS)
	@true
stamp-mt: $(CGENDEPS) $(CPUDIR)/mt.cpu $(CPUDIR)/mt.opc
	$(MAKE) run-cgen arch=mt prefix=mt options= \
		archfile=$(CPUDIR)/mt.cpu \
		opcfile=$(CPUDIR)/mt.opc extrafiles=

$(srcdir)/or1k-desc.h $(srcdir)/or1k-desc.co $(srcdir)/or1k-opc.h $(srcdir)/or1k-opc.co $(srcdir)/or1k-ibld.co $(srcdir)/or1k-opinst.co $(srcdir)/or1k-asm.co $(srcdir)/or1k-dis.co: $(OR1K_DEPS)
	@true
stamp-or1k: $(CGENDEPS) $(CPUDIR)/or1k.cpu $(CPUDIR)/or1k.opc $(CPUDIR)/or1kcommon.cpu $(CPUDIR)/or1korbis.cpu $(CPUDIR)/or1korfpx.cpu
	$(MAKE) run-cgen arch=or1k prefix=or1k options=opinst \
		archfile=$(CPUDIR)/or1k.cpu opcfile=$(CPUDIR)/or1k.opc extrafiles=opinst

$(srcdir)/xstormy16-desc.h $(srcdir)/xstormy16-desc.co $(srcdir)/xstormy16-opc.h $(srcdir)/xstormy16-opc.co $(srcdir)/xstormy16-ibld.co $(srcdir)/xstormy16-asm.co $(srcdir)/xstormy16-dis.co: $(XSTORMY16_DEPS)
	@true
stamp-xstormy16: $(CGENDEPS) $(CPUDIR)/xstormy16.cpu $(CPUDIR)/xstormy16.opc
	$(MAKE) run-cgen arch=xstormy16 prefix=xstormy16 options= \
		archfile=$(CPUDIR)/xstormy16.cpu opcfile=$(CPUDIR)/xstormy16.opc extrafiles=

MOSTLYCLEANFILES = aarch64-gen$(EXEEXT_FOR_BUILD) i386-gen$(EXEEXT_FOR_BUILD) \
	ia64-gen$(EXEEXT_FOR_BUILD) s390-mkopc$(EXEEXT_FOR_BUILD) s390-opc.tab \
	z8kgen$(EXEEXT_FOR_BUILD) opc2c$(EXEEXT_FOR_BUILD)

MAINTAINERCLEANFILES = $(srcdir)/aarch64-asm-2.co $(srcdir)/aarch64-dis-2.co \
	$(srcdir)/aarch64-opc-2.co $(srcdir)/i386-tbl.h $(srcdir)/i386-init.h \
	$(srcdir)/ia64-asmtab.co $(srcdir)/z8k-opc.h \
	$(srcdir)/msp430-decode.co \
	$(srcdir)/rl78-decode.co \
	$(srcdir)/rx-decode.co

aarch64-gen$(EXEEXT_FOR_BUILD): aarch64-gen.o $(BUILD_LIB_DEPS)
	$(LINK_FOR_BUILD) aarch64-gen.o $(BUILD_LIBS)

aarch64-gen.o: aarch64-gen.co $(BFD_H) $(INCDIR)/getopt.h $(INCDIR)/libiberty.h\
	$(INCDIR)/opcode/aarch64.h config.h aarch64-opc.h aarch64-tbl.h
	$(AM_V_CC)$(COMPILE_FOR_BUILD) -c $(srcdir)/aarch64-gen.co

$(srcdir)/aarch64-asm-2.co: @MAINT@ aarch64-gen$(exeext_for_build)
	$(AM_V_GEN)./aarch64-gen$(exeext_for_build) --gen-asm > $@
$(srcdir)/aarch64-dis-2.co: @MAINT@ aarch64-gen$(exeext_for_build)
	$(AM_V_GEN)./aarch64-gen$(exeext_for_build) --gen-dis > $@
$(srcdir)/aarch64-opc-2.co: @MAINT@ aarch64-gen$(exeext_for_build)
	$(AM_V_GEN)./aarch64-gen$(exeext_for_build) --gen-opc > $@

i386-gen$(EXEEXT_FOR_BUILD): i386-gen.o $(BUILD_LIB_DEPS)
	$(AM_V_CCLD)$(LINK_FOR_BUILD) i386-gen.o $(BUILD_LIBS)

i386-gen.o: i386-gen.co i386-opc.h $(srcdir)/../include/opcode/i386.h \
	$(INCDIR)/ansidecl.h $(INCDIR)/getopt.h $(INCDIR)/hashtab.h \
	$(INCDIR)/libiberty.h $(INCDIR)/opcode/i386.h $(INCDIR)/safe-ctype.h \
	config.h i386-opc.h sysdep.h
	$(COMPILE_FOR_BUILD) -c $(srcdir)/i386-gen.co

$(srcdir)/i386-tbl.h: $(srcdir)/i386-init.h
	@echo $@

$(srcdir)/i386-init.h: @MAINT@ i386-gen$(EXEEXT_FOR_BUILD) i386-opc.tbl i386-reg.tbl i386-opc.h
	$(CPP) -P $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) - \
		< $(srcdir)/i386-opc.tbl \
		| ./i386-gen$(EXEEXT_FOR_BUILD) --srcdir $(srcdir)

i386-opc.lo: $(srcdir)/i386-tbl.h

ia64-gen$(EXEEXT_FOR_BUILD): ia64-gen.o $(BUILD_LIB_DEPS)
	$(AM_V_CCLD)$(LINK_FOR_BUILD) ia64-gen.o $(BUILD_LIBS)

ia64-gen.o: ia64-gen.co $(BFD_H) $(INCDIR)/ansidecl.h $(INCDIR)/getopt.h \
	$(INCDIR)/libiberty.h $(INCDIR)/opcode/ia64.h $(INCDIR)/safe-ctype.h \
	$(INCDIR)/symcat.h config.h ia64-opc-a.co ia64-opc-b.co \
	ia64-opc-d.co ia64-opc-f.co ia64-opc-i.co ia64-opc-m.co \
	ia64-opc-x.co ia64-opc.h sysdep.h
	$(COMPILE_FOR_BUILD) -co $(srcdir)/ia64-gen.co

# Use a helper variable for the dependencies to avoid 'make' issues
# with continuations in comments, as @MAINT@ can be expanded to '#'.
ia64_asmtab_deps = ia64-gen$(EXEEXT_FOR_BUILD) ia64-ic.tbl \
	ia64-raw.tbl ia64-waw.tbl ia64-war.tbl
$(srcdir)/ia64-asmtab.co: @MAINT@ $(ia64_asmtab_deps)
	$(AM_V_GEN)./ia64-gen$(EXEEXT_FOR_BUILD) --srcdir $(srcdir) > $@

ia64-opc.lo: $(srcdir)/ia64-asmtab.co

$(srcdir)/msp430-decode.co: @MAINT@ $(srcdir)/msp430-decode.opc opc2c$(EXEEXT_FOR_BUILD)
	$(AM_V_GEN)./opc2c$(EXEEXT_FOR_BUILD) $(srcdir)/msp430-decode.opc > $(srcdir)/msp430-decode.co

$(srcdir)/rl78-decode.co: @MAINT@ $(srcdir)/rl78-decode.opc opc2c$(EXEEXT_FOR_BUILD)
	$(AM_V_GEN)./opc2c$(EXEEXT_FOR_BUILD) $(srcdir)/rl78-decode.opc > $(srcdir)/rl78-decode.co

$(srcdir)/rx-decode.co: @MAINT@ $(srcdir)/rx-decode.opc opc2c$(EXEEXT_FOR_BUILD)
	$(AM_V_GEN)./opc2c$(EXEEXT_FOR_BUILD) $(srcdir)/rx-decode.opc > $(srcdir)/rx-decode.co

opc2c$(EXEEXT_FOR_BUILD): opc2c.o $(BUILD_LIBS_DEPS)
	$(AM_V_CCLD)$(LINK_FOR_BUILD) opc2c.o $(BUILD_LIBS)

opc2c.o: opc2c.co $(INCDIR)/libiberty.h
	$(AM_V_CC)$(COMPILE_FOR_BUILD) -c $(srcdir)/opc2c.co

s390-mkopc$(EXEEXT_FOR_BUILD): s390-mkopc.co
	$(AM_V_CCLD)$(COMPILE_FOR_BUILD) -o s390-mkopc $(srcdir)/s390-mkopc.co

s390-opc.tab: s390-mkopc$(EXEEXT_FOR_BUILD) s390-opc.txt
	$(AM_V_GEN)./s390-mkopc$(EXEEXT_FOR_BUILD) < $(srcdir)/s390-opc.txt > s390-opc.tab

s390-opc.lo: s390-opc.tab

z8kgen$(EXEEXT_FOR_BUILD): z8kgen.o $(BUILD_LIB_DEPS)
	$(AM_V_CCLD)$(LINK_FOR_BUILD) z8kgen.o $(BUILD_LIBS)

z8kgen.o: z8kgen.co
	$(AM_V_CC)$(COMPILE_FOR_BUILD) -c $(srcdir)/z8kgen.co

$(srcdir)/z8k-opc.h: @MAINT@ z8kgen$(EXEEXT_FOR_BUILD)
	$(AM_V_GEN)./z8kgen$(EXEEXT_FOR_BUILD) -a > $@

z8k-dis.lo: $(srcdir)/z8k-opc.h

MIPS_DEFS=`case \`cat ../bfd/ofiles\` in *elfxx-mips*) echo "-DHAVE_BFD_MIPS_ELF_GET_ABIFLAGS=1";; esac`
mips-dis.lo: mips-dis.co
if am__fastdepCC
	$(AM_V_CC)$(LTCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $(MIPS_DEFS) $<
	$(AM_V_at)$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
else
if AMDEP
	source='$<' object='$@' libtool=yes @AMDEPBACKSLASH@
	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) @AMDEPBACKSLASH@
endif
	$(AM_V_CC)$(LTCOMPILE) -c -o $@ $(MIPS_DEFS) $<
endif

sh-dis.lo: sh-dis.co
if am__fastdepCC
	$(AM_V_CC)$(LTCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ @archdefs@ $(srcdir)/sh-dis.co
	$(AM_V_at)mv -f $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
else
if AMDEP
	source='sh-dis.co' object='$@' libtool=yes @AMDEPBACKSLASH@
	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) @AMDEPBACKSLASH@
endif
	$(AM_V_CC)$(LTCOMPILE) -c -o $@ @archdefs@ $(srcdir)/sh-dis.co
endif
