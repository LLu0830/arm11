CC      = gcc
CFLAGS  = -Wall -g -D_POSIX_SOURCE -D_BSD_SOURCE -std=c99 -Werror -pedantic

.SUFFIXES: .c .o

.PHONY: all clean

all: assemble emulate

assemble: assemble.o

emulate: emulate.o

emulate.o: part1_emulator/emulate/pipeline.o part1_emulator/emulator_utility/utility.o part1_emulator/emulate/binaryFileLoader.o part1_emulator/emulator_utility/state.h

pipeline.o: part1_emulator/emulator_utility/state.h part1_emulator/emulator_utility/utility.o part1_emulator/fetch/fetch.o part1_emulator/decode/decode.o part1_emulator/execute/execute.o part1_emulator/emulator_utility/instruction.h part1_emulator/emulator_utility/DefinedTypes.h

utility.o: part1_emulator/emulator_utility/utility.h part1_emulator/emulator_utility/utility.c

fetch.o: part1_emulator/fetch/fetch.h part1_emulator/fetch/fetch.c

decode: part1_emulator/decode/decode.o

decode.o: part1_emulator/decode/decode.h part1_emulator/decode/decode.c

execute.o: part1_emulator/execute/execute.h part1_emulator/execute/execute.c

executeDP.o: part1_emulator/execute/executeDP.h part1_emulator/execute/executeDP.c

executeSDT.o: part1_emulator/execute/executeSDT.h part1_emulator/execute/executeSDT.c

executeMUL.o: part1_emulator/execute/executeMUL.h part1_emulator/execute/executeMUL.c

executeBR.o: part1_emulator/execute/executeBR.h part1_emulator/execute/executeBR.c

binaryFileLoader.o: part1_emulator/emulator_utility/state.h utility.o




clean:
	rm -f $(wildcard *.o)
	rm -f assemble
	rm -f emulate
