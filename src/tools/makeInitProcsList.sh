#!/bin/bash
#-------------------------------------------------------------------------------------------------------------------------------
#
# Description:
#	Every submodule must have its own initialization procedure. But to avoid ring dependence troubles the prototypes are not
#	written in its submodule header file, in this way, also the user will not pushed to use the function directly.
#	But, because wError_init() (in wError.c) use these initialization procedures, it needs their prototypes. So, this scipts
#	creates a file with all the prototypes inside, and wError.c will include it.
#
#	Tag: WERROR_SUBCLASS_INITPROC
#
#-------------------------------------------------------------------------------------------------------------------------------

if [ -n "$1" -o -e "$1" ]; then
	echo "File generating in progress..."
	for func in $(sed -n 's/^[\t ]*\/\/[\t ]*WERROR_SUBCLASS_INITPROC::\(.*\);*/\1/p' *.h)
	do
		echo "void $func (wError_t*);"
	done > $1
else
	echo "ERROR! use $0 <target file-name>"
	exit 127;
fi
exit $?
