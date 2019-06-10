//
// Created by Katarina Kulkova on 02.06.2019.
//
#include "../emulator_utility/DefinedTypes.h"
#include <stdlib.h>
#include <assembler_utility.h>
#include "encodeBR.h"
#include "../assembler_utility/table.h"


uint32_t getCond(char *condition) {
    uint32_t result = 1110;
    switch (*condition) {
        case beq:
            result = 0000;
            break;
        case bge:
            result = 1010;
            break;
        case bgt:
            result = 1100;
            break;
        case ble:
            result = 1101;
            break;
        case blt:
            result = 1011;
            break;
        case bne:
            result = 0001;
            break;
//        case b:
//            result=B
    }
    return result;
}

void encodeBR(assembler_instruction *instruction) {
    address target;
    if (isLabel(instruction->arg1)) {
        target = lookup_pair(instruction->arg1);
    } else {
        target = instruction->arg1;
    }
    uint32_t offset = target - (instruction->currentAddress) - 8;
    char *result = (instruction->mnemonic);
    uint32_t condition = getCond(result);
    instruction->encoded = (condition << 28) | (5 << 25) | ((offset >> 2) & 0x00ffffff);
}




