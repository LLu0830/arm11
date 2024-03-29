cmake_minimum_required(VERSION 3.14)
project(arm11_31 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/part1_emulator/decode)
include_directories(src/part1_emulator/emulate)
include_directories(src/part1_emulator/emulator_utility)
include_directories(src/part1_emulator/execute)
include_directories(src/part1_emulator/fetch)
include_directories(src/part2_assembler/assembler_utility)
include_directories(src/part2_assembler/encode)
include_directories(src/part2_assembler/readInstruction)
include_directories(src/part2_assembler/readLabels)
include_directories(src/part2_assembler/tokenizer)
include_directories(Extension/part4_extension/calculator)
include_directories(Extension/part4_extension/counter)
include_directories(Extension/part4_extension/part4_utility)
include_directories(Extension/part4_extension/presenter)

add_executable(arm11_31
        src/part1_emulator/decode/decode.c
        src/part1_emulator/decode/decode.h
        src/part1_emulator/emulate/binaryFileLoader.c
        src/part1_emulator/emulate/binaryFileLoader.h
        src/part1_emulator/emulate/pipeline.c
        src/part1_emulator/emulate/pipeline.h
        src/part1_emulator/emulator_utility/DefinedTypes.h
        src/part1_emulator/emulator_utility/instruction.c
        src/part1_emulator/emulator_utility/instruction.h
        src/part1_emulator/emulator_utility/state.h
        src/part1_emulator/emulator_utility/utility.c
        src/part1_emulator/emulator_utility/utility.h
        src/part1_emulator/execute/execute.c
        src/part1_emulator/execute/execute.h
        src/part1_emulator/execute/executeBR.c
        src/part1_emulator/execute/executeBR.h
        src/part1_emulator/execute/executeDP.c
        src/part1_emulator/execute/executeDP.h
        src/part1_emulator/execute/executeMUL.c
        src/part1_emulator/execute/executeMUL.h
        src/part1_emulator/execute/executeSDT.c
        src/part1_emulator/execute/executeSDT.h
        src/part1_emulator/fetch/fetch.c
        src/part1_emulator/fetch/fetch.h
        src/part1_emulator/emulate.c

        src/part2_assembler/assembler_utility/assembler_utility.c
        src/part2_assembler/assembler_utility/assembler_utility.h
        src/part2_assembler/assembler_utility/table.c
        src/part2_assembler/assembler_utility/table.h
        src/part2_assembler/encode/encode.c
        src/part2_assembler/encode/encode.h
        src/part2_assembler/encode/encodeBR.c
        src/part2_assembler/encode/encodeBR.h
        src/part2_assembler/encode/encodeDP.c
        src/part2_assembler/encode/encodeDP.h
        src/part2_assembler/encode/encodeMUL.c
        src/part2_assembler/encode/encodeMUL.h
        src/part2_assembler/encode/encodeSDT.c
        src/part2_assembler/encode/encodeSDT.h
        src/part2_assembler/encode/encodeSPECIAL.c
        src/part2_assembler/encode/encodeSPECIAL.h
        src/part2_assembler/readInstruction/readInstruction.c
        src/part2_assembler/readInstruction/readInstruction.h
        src/part2_assembler/readLabels/readLabels.c
        src/part2_assembler/readLabels/readLabels.h
        src/part2_assembler/tokenizer/tokenizer.c
        src/part2_assembler/tokenizer/tokenizer.h
        src/part2_assembler/assemble.c
        Extension/part4_extension/calculator/calculator.c
        Extension/part4_extension/calculator/calculator.h
        Extension/part4_extension/counter/counter.c
        Extension/part4_extension/counter/counter.h
        Extension/part4_extension/part4_utility/part4_utility.c
        Extension/part4_extension/part4_utility/part4_utility.h
        Extension/part4_extension/part4_utility/shine.c
        Extension/part4_extension/part4_utility/shine.h
        Extension/part4_extension/presenter/presenter.c
        Extension/part4_extension/presenter/presenter.h
        Extension/part4_extension/machine.c)

