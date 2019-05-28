cmake_minimum_required(VERSION 3.14)
project(C_Group_31 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(C_Group_31
        src/assemble.c
        src/binaryFileLoader.c
        src/binaryFileLoader.h
        src/decode.c
        src/decode.h
        src/DefinedTypes.h
        src/emulate.c
        src/execute.c
        src/execute.h
        src/executeBR.c
        src/executeBR.h
        src/executeDP.c
        src/executeDP.h
        src/executeMUL.c
        src/executeMUL.h
        src/executeSDT.c
        src/executeSDT.h
        src/fetch.c
        src/fetch.h
        src/instruction.h
        src/pipeline.c
        src/pipeline.h
        src/state.h
        src/utility.c
        src/utility.h)
