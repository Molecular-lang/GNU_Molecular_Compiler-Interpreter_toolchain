#!/bin/sh

# Script to describe a GCC revision based on git hash

short=no
long=no
c=HEAD

for arg in "$@"
do
    case "$arg" in
      --short) short=yes long=no
	;;
      --long|--full) long=yes short=no
	;;
      *) c=$arg
    esac
done

if test x$short = xyes; then
    r=$(git describe --all --match 'basepoints/scpel_compiler-[0-9]*' $c | sed -n 's,^tags/,,;s,^basepoints/scpel_compiler-\([0-9][0-9]*\)-\([0-9][0-9]*\)-g[0-9a-f]*$,r\1-\2,p;s,^basepoints/scpel_compiler-\([0-9][0-9]*\)$,r\1-0,p');
elif test x$long = xyes; then
    r=$(git describe --all --abbrev=40 --match 'basepoints/scpel_compiler-[0-9]*' $c | sed -n 's,^tags/,,;s,^basepoints/scpel_compiler-,r,p')
else
    r=$(git describe --all --abbrev=14 --match 'basepoints/scpel_compiler-[0-9]*' $c | sed -n 's,^tags/,,;s,^basepoints/scpel_compiler-,r,p')
    expr ${r:-no} : 'r[0-9]\+$' >/dev/null && r=${r}-0-g$(git rev-parse $c);
fi;
if test -n $r; then
    o=$(git config --get scpel_compiler-config.upstream);
    rr=$(echo $r | sed -n 's,^r\([0-9]\+\)-[0-9]\+\(-g[0-9a-f]\+\)\?$,\1,p');
    if git rev-parse --verify --quiet ${o:-origin}/releases/scpel_compiler-$rr >/dev/null; then
	m=releases/scpel_compiler-$rr;
    else
	m=master;
    fi;
    git merge-base --is-ancestor $c ${o:-origin}/$m && echo ${r};
fi;
