//
// Created by mw6118 on 26/05/19.
//

// (Rini) includes instructionType enum - having this header here reduces repetition

#import "execute.h"


#include "DefinedTypes.h"


#ifndef C_GROUP_31_INSTRUCTION_H
#define C_GROUP_31_INSTRUCTION_H

#import "execute.h"
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
    bool upBit;>>>>>>> b0a83b923c19818035ee06d5f905b2df93c76e5c

    bool storeBit;


} instruction_type;
#endif //C_GROUP_31_INSTRUCTION_H

