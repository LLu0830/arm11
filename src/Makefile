CC      = gcc
CFLAGS  = -Wall -g -D_POSIX_SOURCE -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic
VPATH   = part1_emulator/decode:part1_emulator/emulate:part1_emulator/emulator_utility:part1_emulator/execute:part1_emulator/fetch:part1_emulator

.SUFFIXES: .c .o

.PHONY: all clean

all: assemble emulate

assemble: assemble.o

emulate: emulate.o pipeline.o utility.o fetch.o decode.o execute.o executeDP.o executeSDT.o executeMUL.o executeBR.o binaryFileLoader.o printOutput.o




clean:
	rm -f $(wildcard *.o)
	rm -f assemble
	rm -f emulate
