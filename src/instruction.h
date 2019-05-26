//
// Created by MANSHU WANG on 5/24/2019.
//

// (Rini) includes instructionType enum - having this header here reduces repetition
#import "execute.h"

#ifndef C_GROUP_31_INSTRUCTION_H
#define C_GROUP_31_INSTRUCTION_H

#endif //C_GROUP_31_INSTRUCTION_H
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

enum Cond{
    EQ,
    NE,
    GE,
    LT,
    GT,
    LE,
    AL
};
