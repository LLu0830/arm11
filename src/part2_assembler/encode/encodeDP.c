//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "encodeDP.h"
#include "../assembler_utility/table.h"
#include <string.h>

void encodeDPCompute(assembler_instruction *instruction) {
    token mnemonic = instruction->mnemonic;


}

void encodeDPAssign(assembler_instruction *instruction) {
    token rdString = instruction->arg1;
    uint32_t i, opCode, rn, rd, operand2;
//
    opCode = 0xd;
    uint32_t registerNo = (uint32_t) (*rdString - '0');

}

void encodeDPSetFlags(assembler_instruction *instruction) {

}

void encodeDP(assembler_instruction *instruction) {
    token *mnemonic = instruction->mnemonic;
    switch (**mnemonic) {
        case 'm':
            encodeDPCompute(instruction);
            break;
        case 't':
        case 'c':
            encodeDPAssign(instruction);
            break;
        default:
            encodeDPSetFlags(instruction);
            break;
    }

    instruction->encoded = concatDP(instruction);

}

uint32_t concatDP(assembler_instruction *instruction) {

}