//
// Created by MANSHU WANG on 6/4/2019.
//
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "encodeSPECIAL.h"
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/utility.h"
#include "../assembler_utility/assembler_utility.h"

void encodeSPECIAL(assembler_instruction *instruction) {
    token mnemonic = instruction->mnemonic;

    switch (*mnemonic) {
        case 'a':
            //maybe need to check if operand1,2,3 all = 0;
            if (!strcmp(instruction->arg1, "r0")
                && !strcmp(instruction->arg2, "r0")
                && !strcmp(instruction->arg3, "r0")) {
                instruction->encoded = 0x0;
            }
            break;
        case 'l':
            // case DP: Operand2 is a register, shifted by a constant amount

            //cond field set to 1110
            uint32_t cond = 0xe;

            //set i bit to 0
            uint32_t IBit = 0;
            //set opcode to mov


            //set s bit to 0
            uint32_t SBit = 0;

            // shifted amount
            token shiftAmount = instruction->arg3;
            uint32_t shiftA = (uint32_t) strtol(shiftAmount + 1, NULL, 16);

            //shift type = lsl 00
            uint32_t shiftType = 0;
            //get Rn from org2
            token rn = instruction->arg2;
            uint32_t positionRn = (uint32_t) strtol((rn + 1), NULL, 16);

            break;
        default:
            break;
    }
}
