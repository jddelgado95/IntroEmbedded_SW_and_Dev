#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# 2nd assesment for the courser. This file provides an automated build process 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	file.o Builds a object file
#	file.i Builds a preprocessed file
#	file.d Builds dependency file
#	file.asm Dumps assembly file
#	compille-all command compiles the source files of the assesment
#	clean Cleans and remove all the generated object map asm etc etc files
#	Build builds and links the object files in the assesment	
#      
#
# Platform Overrides:
#	HOST is the default platform
#	MSP432 target for the cross compile platform
#      
#Author: Diego Delgado V jdiegodelgado20
#Date: 16.05.2021
#------------------------------------------------------------------------------
include sources.mk

#platform overrides
PLATFORM = HOST

#General flags for both platforms
GEN_FLAGS = \
	-Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99

TARGET = c1m2

ifeq ($(PLATFORM),MSP432)
	# Arch Specific Flags
	LINKER_FILE = -T msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECHS = nosys.specs
	EXTRA = -mthumb \
		-mfloat-abi=hard \
		-mfpu = fpv4-sp-d16

	#Compiler flags and defines var
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = $(GEN_FLAGS) $(EXTRA) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T -L ../ $(LINKER_FILE)
	CPPFLAGS= -DMSP432 $(INCLUDES)
	
	#Arch specific source codes
	SOURCE = \
		main.c \
		memory.c \
		interrupts_msp432p401r_gcc.c \
		startup_msp432p401r_gcc.c \
		system_msp432p401r.c
 
	SIZE = arm-none-eabi-size

else
	#Compiler flags and def
	CC = gcc
	CFLAGS = $(GEN_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size

endif

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
ASMS = $(SRCS:.c=.asm)
PREP = $(SRCS:.c=.i)

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@


%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: Build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: Clean
clean: 
	-rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map






