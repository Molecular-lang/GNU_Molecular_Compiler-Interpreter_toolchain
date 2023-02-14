#!/bin/sh

# allocfail.sh -- Test for libbacktrace library.

set -e

if [ ! -f ./allocfail ]; then
    # Hard failure.
    exit 99
fi

allocs=$(./allocfail 2>&1)
if [ "$allocs" = "" ]; then
    # Hard failure.
    exit 99
fi

# This generates the following output:
# ...
# $ allocfail.sh
# allocs: 80495
# Status changed to 0 at 1
# Status changed to 1 at 3
# Status changed to 0 at 11
# Status changed to 1 at 12
# Status changed to 0 at 845
# ...
#
# We have status 0 for an allocation failure at:
# - 1 because backtrace_create_state handles failure robustly
# - 2 because the fail switches backtrace_full to !can_alloc mode.
# - 11 because failure of elf_open_debugfile_by_buildid does not generate an
#   error callback beyond the one for the allocation failure itself.

echo "allocs: $allocs"

step=1
i=1
passes=0
prev_status=-1
while [ $i -le $allocs ]; do
    if ./allocfail $i >/dev/null 2>&1; status=$?; then
	true
    fi
    if [ $status -gt 1 ]; then
	echo "Unallowed fail found: $i"
	# Failure.
	exit 1
    fi

    # The test-case would run too long if we would excercise all allocs.
    # So, run with step 1 initially, and increase the step once we have 10
    # subsequent passes, and drop back to step 1 once we encounter another
    # failure.  This takes ~2.6 seconds on an i7-6600U CPU @ 2.60GHz.
    if [ $status -eq 0 ]; then
	passes=$(($passes + 1))
	if [ $passes -ge 10 ]; then
	    step=$((step * 10))
	    passes=0
	fi
    elif [ $status -eq 1 ]; then
	passes=0
	step=1
    fi

    if [ $status -ne $prev_status ]; then
	echo "Status changed to $status at $i"
    fi
    prev_status=$status

    i=$(($i + $step))
done

# Success.
exit 0
