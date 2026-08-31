#!/bin/bash
#-------------------------------------------------------------------------------------------------------------------------------
#
# Description:
#	It retrives the submodule header-files list and creates a file that includes all of them. Then, using the "#include"
#	statement in wError.h, it will includes all the submodules header files. In this way, every time you will add a new
#	submodule, you will NOT NEED to modify the wError.c file.
#
#-------------------------------------------------------------------------------------------------------------------------------

PREFIX="wErrorWith"

if [ -n "$1" ]; then
	echo "File generating in progress..."
	ls ${PREFIX}*.h |sed -n 's/\(.*\.h\)/#include <\1>/p' > $1
else
	echo "ERROR! use $0 <target file-name>"
	exit 127;
fi
exit $?
