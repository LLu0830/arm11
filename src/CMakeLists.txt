cmake_minimum_required(VERSION 3.14)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        multiplyInstruction/Multiply.c
        assemble.c
        binaryFileLoader.h
        decode.c
        decode.h
        emulate.c
        execute.c
        execute.h
        executeBR.c
        executeBR.h
        executeDP.c
        executeDP.h
        executeMUL.c
        executeMUL.h
        executeSDT.c
        executeSDT.h
        fetch.c
        fetch.h
        instruction.h
        pipeline.c
        pipeline.h
        utility.c
        utility.h binaryFileLoader.c)
