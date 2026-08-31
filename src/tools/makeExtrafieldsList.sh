#!/bin/bash

TGTFILE="$1"

if [ -n "$TGTFILE" ]; then
	echo "File generating in progress..."
	echo "// --- self generated code ---" > "$TGTFILE"
	for hFile in $(grep -l 'WERROR_SUBCLASS_EXTRAFIELD' *.h)
	do
		echo -e "\t ${hFile%.h}"
		sed -n 's/^[\t ]*\/\/[\t ]*WERROR_SUBCLASS_EXTRAFIELD::\(.*\);*/\1;/p' "$hFile" >> "$TGTFILE"
	done
	echo "// ---------------------------" >> "$TGTFILE"
else
	echo "ERROR! use $0 <target file-name>"
	exit 127;
fi
exit $?
