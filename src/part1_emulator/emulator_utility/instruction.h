//
// Created by mw6118 on 26/05/19.
//

// (Rini) includes instructionType enum - having this header here reduces repetition


#ifndef C_GROUP_31_INSTRUCTION_H
#define C_GROUP_31_INSTRUCTION_H

#include "DefinedTypes.h"
#include <stdbool.h>

typedef struct {

    InstructionType instructionType;
    //first 4bits condition
    Cond conditionType;

    //
    register_address rd;
    register_address rn;
    register_address rs;
    register_address rm;

    //opcode in data processing
    OpCode operationType;

    //12/24bits operand2
    uint32_t offsets_or_operand2;

    // in data processing
    bool I;

    // Set condition code
    // in dataProcessing, Multiply
    bool S;


    //in Multiply
    bool accumulate;


    //in Single Data Transfer
    bool immediateOffset;
    bool Pre_Post;

    bool upBit;


    bool L;

}Instruction;

#endif //C_GROUP_31_INSTRUCTION_H

