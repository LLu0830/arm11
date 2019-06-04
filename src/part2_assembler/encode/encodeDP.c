//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "encodeDP.h"
#include "../assembler_utility/table.h"
#include <string.h>

void encodeDPCompute(assembler_instruction *instruction) {
    char *mnemonic = instruction->mnemonic->name;


}

void encodeDPAssign(assembler_instruction *instruction) {
    char *rd = instruction->arg1->name;
    instruction->arg1
    uint32_t registerNo = (uint32_t) *rd - '0';

}

void encodeDPSetFlags(assembler_instruction *instruction) {

}

void encodeDP(assembler_instruction *instruction) {
    char *mnemonic = instruction->mnemonic->name;
    switch (*mnemonic) {
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