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

uint32_t getCond(Mnemonic operationType) {
    uint32_t result;
    switch (operationType) {
        case beq:
            result = EQ;
            break;
        case bge:
            result = GE;
            break;
        case bgt:
            result = GT;
            break;
        case ble:
            result = LE;
            break;
        case blt:
            result = LT;
            break;
        case bne:
            result = NE;
            break;
        case b:
            result = AL;
            break;
        default:
            exit(EXIT_FAILURE);
    }
    return result;
}


void encodeBR(assembler_instruction *instruction, label_address_list *table) {
    address target;
    if (isContainedInTable(instruction->arg1, table)) {
        target = lookup_address(instruction->arg1, table);
    } else {
        target = getPosFromChar(instruction->arg1);
    }
    uint32_t offset = target - (instruction->currentAddress) - 2;

    uint32_t condition = getCond(instruction->operationType);

    instruction->encoded = (condition << 28U) | (5U << 25U) | ((offset) & 0x00ffffffU);
}
