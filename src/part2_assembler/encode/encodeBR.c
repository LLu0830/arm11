//
// Created by Katarina Kulkova on 02.06.2019.
//
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"
#include <stdlib.h>
#include "../assembler_utility/assembler_utility.h"
#include "encodeBR.h"
#include "../assembler_utility/table.h"
#include "encodeMUL.h"
#include "encodeSDT.h"

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
//            result = 1110;
    }
    return result;
}



void encodeBR(assembler_instruction *instruction, label_address_list *table) {
//    address target;
//    if (isContainedInTable(instruction->arg1, table)) {
//        target = lookup_address(instruction->arg1, table);
//    } else {
//        target = getValue(instruction->arg1);
//    }
    printf("%p", instruction);
    uint32_t offset = instruction->currentAddress;
    printf("%u", offset);
//    if (instruction->currentAddress + 8 <= target) {
//        offset = target - instruction->currentAddress - 8;
//    } else {
//        offset = instruction->currentAddress - target - 8;
//    }
    char *result = instruction->mnemonic;
    printf("%s", result);
    uint32_t condition = getCond(result);
    printf("%u", condition);
    instruction->encoded = (condition << 28U) | (5U << 25U) | ((offset >> 2U) & 0x00ffffffU);
    printf("%u", instruction->encoded);
    //printf("%u",instruction->encoded);
}
