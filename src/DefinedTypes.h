//
// Created by MANSHU WANG on 5/24/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#ifndef C_GROUP_31_TYPES_H
#define C_GROUP_31_TYPES_H

typedef enum{
    AND,
    EOR,
    SUB,
    RSB,
    ADD,
    TST,
    TEQ,
    CMP,
    ORR,
    MOV
} OpCode;


typedef enum{
    DataProcessing,
    Multiply,
    SingleDataTransfer,
    Branch,
    Halt
}InstructionType;



typedef enum{
    EQ = 0x0,
    NE = 0x1,
    GE = 0xA,
    LT = 0xB,
    GT = 0xC,
    LE = 0xD,
    AL = 0xE
} Cond;


typedef enum {


    //last result negative
    N = 0x8,

    //last result zero
    Z = 0x4,

    //caused a bit to be carried out
    C = 0x2,

    //last result overflowed
    V = 0x0

} CPSR_helper;

typedef uint8_t register_address;


#endif //C_GROUP_31_INSTRUCTION_H

