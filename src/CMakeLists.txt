cmake_minimum_required(VERSION 3.14)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        assemble.c
        part1_emulator/emulate/binaryFileLoader.h
        part1_emulator/decode/decode.c
        part1_emulator/decode/decode.h
        part1_emulator/emulate.c
        part1_emulator/execute/execute.c
        part1_emulator/execute/execute.h
        part1_emulator/execute/executeBR.c
        part1_emulator/execute/executeBR.h
        part1_emulator/execute/executeDP.c
        part1_emulator/execute/executeDP.h
        part1_emulator/execute/executeMUL.c
        part1_emulator/execute/executeMUL.h
        part1_emulator/execute/executeSDT.c
        part1_emulator/execute/executeSDT.h
        part1_emulator/fetch/fetch.c
        part1_emulator/fetch/fetch.h
        "part1_emulator/emulator_utility/instruction.h"
        part1_emulator/emulate/pipeline.c
        part1_emulator/emulate/pipeline.h
        "part1_emulator/emulator_utility/utility.c"
        "part1_emulator/emulator_utility/utility.h" part1_emulator/emulate/binaryFileLoader.c)
