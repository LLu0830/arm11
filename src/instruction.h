//
// Created by mw6118 on 26/05/19.
//
<<<<<<< HEAD

// (Rini) includes instructionType enum - having this header here reduces repetition
#import "execute.h"

=======
#include "DefinedTypes.h"
>>>>>>> dec3e21c2400928967b863e88f33ca1db3888950
#ifndef C_GROUP_31_INSTRUCTION_H
#define C_GROUP_31_INSTRUCTION_H


typedef struct {

    InstructionType instructionType;

    //first 4bits condition
    Cond conditionType;


    //
    register_address rd;
    register_address rn;
    register_address rs;
    register_address rm;

    //opcode in dataprocessing
    OpCode operationType;

    //12/24bits operand
    uint32_t offsets_or_operand;
    //...

    // in data processing
    bool immediateOperand;

    // Set condition code
    // in dataProcessing, Multiply
    bool scc;


    //in Multiply
    bool accumulate;


    //in Single Data Transfer
    bool immediateOffset;
    bool Pre_Post;
    bool upBit;
    bool storeBit;


}instruction_type;
#endif //C_GROUP_31_INSTRUCTION_H
<<<<<<< HEAD
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
=======
>>>>>>> dec3e21c2400928967b863e88f33ca1db3888950
