#------------------------------------------------------------------------------------------------------------------------------
#
#                                                        _____                     
#                                              __      _| ____|_ __ _ __ ___  _ __ 
#                                              \ \ /\ / /  _| | '__| '__/ _ \| '__|
#                                               \ V  V /| |___| |  | | | (_) | |   
#                                               \_/\_/ |_____|_|  |_|  \___/|_|   
#
#
#
#
# File:     Makefile
#
# Author:	Silvano Catinella
#
# Description:
#	Rules for the bin-object file building
#	
# Editor settings: cols:128, tab-size:6
#------------------------------------------------------------------------------------------------------------------------------
srcs   := $(shell ls *.c)
objs   := $(srcs:.c=.o)
shobjs := $(srcs:.c=-so.o)
hmods  := $(shell ls wErrorWith*.h)

GDB     ?= 0
INCOPTS ?= -I.

ifeq ($(GDB), 1)
	CCOPTS = -Wall -g
else
	CCOPTS = -Wall
endif

hmodsListFile = wErrorSubmodulesList.h
extraFldsFile = extraFldsFile.x
intProcsFile  = intProcsFile.x
initCSectFile = initCSectFile.x

#------------------------------------------------------------------------------------------------------------------------------
#                                                     R U L E S
#------------------------------------------------------------------------------------------------------------------------------
.PHONY:		all clean

all:			$(hmodsListFile) $(extraFldsFile) $(intProcsFile) $(initCSectFile) libwError.so libwError.a

$(hmodsListFile):	$(hmods)
			@echo "[ GEN(1) ] $@"
			@tools/makeHeadersList.sh $@

$(extraFldsFile):
			@echo "[ GEN(2) ] $@"
			@tools/makeExtrafieldsList.sh $@

$(intProcsFile):
			@echo "[ GEN(3) ] $@"
			@tools/makeInitProcsList.sh $@

$(initCSectFile):
			@echo "[ GEN(4) ] $@"
			@tools/makeInitCaseSection.pl $@

libwError.so:	wError.o $(objs)
			@echo "[ LD(1) ] $@"
			@$(CC) -shared -o $@ $^

libwError.a:	wError-so.o $(shobjs)
			@echo "[ LD(2) ] $@"
			@ar rcs $@ $^

%.o:			%.c %.h 
			@echo "[ CC ]  $@"
			@$(CC) $(CCOPTS) $(INCOPTS) -o $@ -c $<

%-so.o:		%.c %.h 
			@echo "[ CC-SO ]  $@"
			@$(CC) $(CCOPTS) $(INCOPTS) -o $@ -c -fPIC $<
			
clean:
			@echo "[ CLEAN ]"
			@rm -fv $(objs) $(shobjs) $(hmodsListFile) $(extraFldsFile) $(intProcsFile) $(initCSectFile)

cleanall:		clean
			@rm -fv libwError.so libwError.a
