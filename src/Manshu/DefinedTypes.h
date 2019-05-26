//
// Created by MANSHU WANG on 5/24/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#ifndef C_GROUP_31_INSTRUCTION_H
#define C_GROUP_31_INSTRUCTION_H

enum OpCode{
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
};


enum InstructionType{
    DataProcessing,
    Multiply,
    SingleDataTransfer,
    Branch
};



enum Cond{
    EQ,
    NE,
    GE,
    LT,
    GT,
    LE,
    AL
};


typedef uint8_t register_address;
typedef



#endif //C_GROUP_31_INSTRUCTION_H

