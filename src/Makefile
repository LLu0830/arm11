CC      = gcc
CFLAGS  = -Wall -g -D_POSIX_SOURCE -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic
VPATH   = part1_emulator/decode:part1_emulator/emulate:part1_emulator/emulator_utility:part1_emulator/execute:part1_emulator/fetch:part1_emulator:part2_assembler:part2_assembler/assembler_utility:part2_assembler/encode:part2_assembler/readInstruction:part2_assembler/readLabels:part2_assembler/tokenizer

.SUFFIXES: .c .o

.PHONY: all clean

all: emulate assemble

emulate: emulate.o pipeline.o utility.o fetch.o decode.o execute.o executeDP.o executeSDT.o executeMUL.o executeBR.o binaryFileLoader.o printOutput.o

assemble: assembler_utility.o table.o encode.o encodeBR.o encodeDP.o encodeMUL.o encodeSDT.o encodeSPECIAL.o readInstruction.o readLabels.o  tokenizer.o assemble.o



clean:
	rm -f $(wildcard *.o)
	rm -f emulate assemble
