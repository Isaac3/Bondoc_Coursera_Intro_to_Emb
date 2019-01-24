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
# <Put a Description Here>
# This makefile can compile multiple source files and support two platform 
# targets. These targets are the MSP432 and the HOST. This file will also
# generate preprocessor, assembly, object, dependency, executable, and map
# output files.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#      The supported targets are the HOST and the MSP432
#      build - Builds and links all source files
#      all - Same as build
#      clean - Removes all generated files
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#      PLATFORM - Specifies the architecture (HOST, MSP432)
#      
#------------------------------------------------------------------------------
include sources.mk


# Platform Overrides
PLATFORM = $(PLATFORM)



# Architectures Specific Flags

ifeq ($(PLATFORM), HOST)
  CC = gcc
  CPPFLAGS = 
  CFLAGS = -Wall   \
           -Werror \
           -g	   \
	   -std = c99
	# something else should probably go here
endif

ifeq ($(PLATFORM), MSP432)
  CPU = cortex-m4
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  ARCH = armv7e-m
  FPU = fpv4-sp-d16
  SPECS = nosys.specs
  LINKER_FILE = msp432p401r.lds
  CPPFLAGS =
  CFLAGS =  -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard \
            -m$(FPU) --specs=$(SPECS) 
	# some other platform specific flag	
endif


# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
TARGET = c1m2
FLAGS = -Wall	\
	-Werror \
	-g	\
	-std=c99
LDFLAGS = -Wl, -Map=$(TARGET).map -T $(LINKER_FILE) -O0
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) $(FLAGS)
CPPFLAGs = 

OBJS = $(SRCS:.c:.o)

%.o : %.c 
	%(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map
