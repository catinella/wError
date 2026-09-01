#!/usr/bin/python3
#------------------------------------------------------------------------------------------------------------------------------
#
#                                                        _____                     
#                                              __      _| ____|_ __ _ __ ___  _ __ 
#                                              \ \ /\ / /  _| | '__| '__/ _ \| '__|
#                                               \ V  V /| |___| |  | | | (_) | |   
#                                                \_/\_/ |_____|_|  |_|  \___/|_|   
#
#
#
#
# File:     wInclude.py
#
# Author:	Silvano Catinella
#
# Description:
#	Rules for the bin-object file building
#	
# Editor settings: cols:128, tab-size:6
#------------------------------------------------------------------------------------------------------------------------------

import argparse
import re
import os


err    = 0
db     = {}
parser = argparse.ArgumentParser()

parser.add_argument(
	"--template",
	required = True,
	action   = "store",
	help     = "The template file to fill"
)

parser.add_argument(
	"--tgtFile",
	required = True,
	action   = "store",
	help     = "The filled text file"
)

parser.add_argument(
	"--verbose",
	required = False,
	action = "store_true",
	help   = "It increcmets the output verbosity level"
)

args = parser.parse_args()

if (os.path.exists(args.template) == False):
	print('ERROR! "{}" template-file not found'.format(args.template))
	err = 131

else :
	templFH = open(args.template, "r")
	tgtFH   = open(args.tgtFile,  "w")

	for line in templFH:
		if (re.match(r'^[ \t]*#winclude <[^ \t>]+>[ \t]*$', line)):
			line = line.rstrip("\r\n")
			incFile = re.sub(r'^[ \t]*#winclude <([^ \t>]+)>[ \t]*$', r'\1', line)
			if (os.path.exists(incFile) == False):
				print('ERROR! "{}" file not found'.format(incFile))
				err = 133
				break

			else:
				incFH = open(incFile, "r")
				for row in incFH:
					tgtFH.write(row)
				incFH.close();
		else:
			tgtFH.write(line)
	
	templFH.close()
	tgtFH.close()

exit(err)
