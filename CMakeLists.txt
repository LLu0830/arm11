cmake_minimum_required(VERSION 3.12)
project(arm11_31 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/part1_emulator/decode)
include_directories(src/part1_emulator/emulate)
include_directories(src/part1_emulator/emulator_utility)
include_directories(src/part1_emulator/execute)
include_directories(src/part1_emulator/fetch)

add_executable(arm11_31
        src/part1_emulator/decode/decode.c
        src/part1_emulator/decode/decode.h
        src/part1_emulator/emulate/binaryFileLoader.c
        src/part1_emulator/emulate/binaryFileLoader.h
        src/part1_emulator/emulate/pipeline.c
        src/part1_emulator/emulate/pipeline.h
        src/part1_emulator/emulate/printOutput.c
        src/part1_emulator/emulate/printOutput.h
        src/part1_emulator/emulator_utility/DefinedTypes.h
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
        src/assemble.c)
