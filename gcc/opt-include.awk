#  Please review: $(src-dir)/SPL-README for Licencing info.

# This Awk script reads in the option records and emits the include files
# listed by the HeaderInclude directive.

BEGIN {
	h_next = 0
	c_next = 0
}

(h_next != 0)	  { print "OPTIONS_H_EXTRA += $(srcdir)/" $1; h_next = 0 }
(c_next != 0)	  { print "OPTIONS_C_EXTRA += $(srcdir)/" $1; c_next = 0 }
/^HeaderInclude$/ { h_next = 1; c_next = 0 }
/^SourceInclude$/ { h_next = 0; c_next = 1 }
