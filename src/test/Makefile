#------------------------------------------------------------------------------------------------------------------------------
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
-include Makefile.conf

srcs := $(shell ls *.c)
objs := $(srcs:.c=.o)
exes := $(srcs:.c=)
deps := $(shell ls ../wError*.c)
depo := $(deps:.c=.o)

CC      = gcc
GDB     ?= 0
INCOPTS ?= -I.. -I.

ifeq ($(GDB), 1)
	CCOPTS = -Wall -g
else
	CCOPTS = -Wall
endif

.PHONY: all clean


all:		depbuild $(exes)

%.o:		%.c
		@echo "[ CC ] $@"
		@$(CC) $(CCOPTS) $(INCOPTS) -o $@ -c $<

%_test:	%_test.o $(depo)
		@echo "[ LD ] $@"
		@$(CC) $(CCOPTS) -o $@ $^

depbuild:
		@make --no-print-directory -C ../ GDB=$(GDB) all

clean:
		@echo "[CLEAN] $@"
		@rm -fv $(objs)
		@make --no-print-directory -C ../ clean

cleanall:	clean
		@rm -fv $(exes)
