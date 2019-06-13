CC      = gcc
CFLAGS  = -Wall -g -D_DEFAULT_SOURCE -std=c99 -Werror -pedantic
VPATH   = part1_emulator/decode:part1_emulator/emulate:part1_emulator/emulator_utility:part1_emulator/execute:part1_emulator/fetch:part1_emulator:part2_assembler:part2_assembler/assembler_utility:part2_assembler/encode:part2_assembler/readInstruction:part2_assembler/readLabels:part2_assembler/tokenizer:part4_extension/part4_utility:part4_extension/presenter:part4_extension/calculator:part4_extension/counter:part4_extension

.SUFFIXES: .c .o

.PHONY: all clean

all: emulate assemble machine

emulate: emulate.o pipeline.o utility.o fetch.o decode.o execute.o executeDP.o executeSDT.o executeMUL.o executeBR.o binaryFileLoader.o printOutput.o

assemble: utility.o assembler_utility.o table.o encode.o encodeBR.o encodeDP.o encodeMUL.o encodeSDT.o encodeSPECIAL.o readInstruction.o readLabels.o  tokenizer.o assemble.o

machine: machine.o calculator.o counter.o part4_utility.o RPI.o shine.o presenter.o

clean:
	rm -f $(wildcard *.o)
	rm -f emulate assemble machine
