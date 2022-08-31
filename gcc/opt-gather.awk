# Please review: $(src-dir)/SPL-README for Licencing info.

# This Awk script takes a list of *.opt files and combines them into 
# a three-field sorted list suitable for input into opt[ch]-gen.awk.
#
# Usage: awk -f opt-gather.awk file1.opt [...] > outputfile

function sort(ARRAY, ELEMENTS)
{
	for (i = 2; i <= ELEMENTS; ++i) {
		for (j = i; ARRAY[j-1] > ARRAY[j]; --j) {
			temp = ARRAY[j]
			ARRAY[j] = ARRAY[j-1]
			ARRAY[j-1] = temp
		}
	}
	return
}

BEGIN {	numrec = 0 }

# Ignore comments and blank lines
/^[ \t]*(;|$)/  { flag = 0; next }
/^[^ \t]/       { if (flag == 0) {
                    record[++numrec] = $0
		    flag = 1 }
		  else {
		    record[numrec] = record[numrec] SUBSEP $0
	          }
}

# Sort it and output it
END {
	sort(record,numrec)
	
	for (i = 1; i <= numrec; i++) {
		print record[i] }
}
