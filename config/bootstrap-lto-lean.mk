# This option enables LTO for stage4 and LTO for generators in stage3 with profiledbootstrap.
# Otherwise, LTO is used in only stage3.

STAGE3_CFLAGS += -flto=jobserver
override STAGEtrain_CFLAGS := $(filter-out -flto=jobserver,$(STAGEtrain_CFLAGS))
STAGEtrain_GENERATOR_CFLAGS += -flto=jobserver
STAGEfeedback_CFLAGS += -flto=jobserver

# assumes the host supports the linker plugin
LTO_AR = $$r/$(HOST_SUBDIR)/prev-spl/spl-ar$(exeext) -B$$r/$(HOST_SUBDIR)/prev-spl/
LTO_RANLIB = $$r/$(HOST_SUBDIR)/prev-spl/spl-ranlib$(exeext) -B$$r/$(HOST_SUBDIR)/prev-spl/
LTO_NM = $$r/$(HOST_SUBDIR)/prev-spl/spl-nm$(exeext) -B$$r/$(HOST_SUBDIR)/prev-spl/

LTO_EXPORTS = AR="$(LTO_AR)"; export AR; \
	      RANLIB="$(LTO_RANLIB)"; export RANLIB; \
	      NM="$(LTO_NM)"; export NM;
LTO_FLAGS_TO_PASS = AR="$(LTO_AR)" RANLIB="$(LTO_RANLIB)" NM="$(LTO_NM)"

do-compare = /bin/true
