//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "encodeDP.h"
#include "../assembler_utility/table.h"
#include <string.h>
#include "../../part1_emulator/emulator_utility/instruction.h"

uint32_t getExpressionFromOp2(token op2Pointer) {
    uint32_t expression;
    if (strlen(op2Pointer) == 1) {
        expression = (uint32_t) *op2Pointer;
    } else {
        if (*(op2Pointer + 1) == 'x') {
            expression = (uint32_t) strtol(op2Pointer + 2, NULL, 16);
        } else {
            expression = (uint32_t) strtol(op2Pointer, NULL, 10);
        }
    }
    return expression;
}

void encodeDPCompute(assembler_instruction *assembler_instruction, Instruction *emulator_instruction) {
//  setting S bit to 0
    emulator_instruction->S = 0;
}

void encodeDPAssign(assembler_instruction *assembler_instruction, Instruction *emulator_instruction) {
    token rdString = assembler_instruction->arg1;

//  rn not used here, so we can set it to any value
    emulator_instruction->rn = 0x0;

//  getting number of destination register rd
    emulator_instruction->rd = (uint32_t) (*rdString - '0');

//  getting immediate value from operand2
    emulator_instruction->offsets_or_operand2 = getExpressionFromOp2(assembler_instruction->arg2);

//  setting S bit to 0
    emulator_instruction->S = 0;

}

void encodeDPSetFlags(assembler_instruction *assembler_instruction, Instruction *emulator_instruction) {

//  Setting S bit to 1
    emulator_instruction->S = 1;



}

void encodeDP(assembler_instruction *assembler_instruction) {
    token mnemonic = assembler_instruction->mnemonic;
    Instruction emulator_instruction;
    switch (*mnemonic) {
        case 'm':
            emulator_instruction.operationType = MOV;
            encodeDPCompute(assembler_instruction, &emulator_instruction);
            break;
        case 't':
        case 'c':
            encodeDPAssign(assembler_instruction, &emulator_instruction);
            break;
        default:
            encodeDPSetFlags(assembler_instruction, &emulator_instruction);
            break;
    }

    emulator_instruction.conditionType = AL;
    assembler_instruction->encoded = concatDP(&emulator_instruction);

}

uint32_t concatDP(Instruction *emulator_instruction) {

}
