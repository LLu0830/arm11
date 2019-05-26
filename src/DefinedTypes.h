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


typedef struct{

    uint8_t
    //last result negative
    bool N;

    //last result zero
    bool Z;

    //caused a bit to be carried out
    bool C;

    //last result overflowed
    bool V;

} CPSR;

typedef uint8_t register_address;


#endif //C_GROUP_31_INSTRUCTION_H

