//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <string.h>
#include <stdlib.h>
#include "encodeMUL.h"
#include "../assembler_utility/table.h"
#include "../assembler_utility/assembler_utility.h"
#include "../../part1_emulator/emulator_utility/utility.h"

uint32_t getPosFromChar(token pos){
    return strtol((pos + 1), NULL, 16);
}


void encodeMUL(assembler_instruction *instruction) {
    uint32_t const1 = 0x9;

    // change S bit to 0
    uint32_t SBit = 0;

    //set condition to 1110
    uint32_t cond = 0xe;


    // set 16-19(Rd) with operand1
    token rd = instruction->arg1;
    uint32_t positionRd  = getPosFromChar(rd);

    //set 0-3(Rm) with operand2
    token rm =instruction->arg2;
    uint32_t positionRm  = getPosFromChar(rm);

    // set 8-11(Rs) with operand3
    token rs = instruction->arg3;
    uint32_t positionRs  = getPosFromChar(rs);


    uint32_t positionRn = 0;
    uint32_t ABit = 0;

    switch (instruction->operationType) {
        case mul:
            // change A bit to 0
            ABit = 0;
            break;
        case mla:
            // change A bit to 1
            ABit = 1;
            // set 12-15(Rn) with operand4
            token rn = instruction->arg4;
            positionRn  = (unsigned int) *(rn + 1) - '0';
            break;
        default:
            exit(EXIT_FAILURE);
    }

    uint32_t result = 0;

    result |= cond << 28U;
    result |= ABit << 21U;
    result |= SBit << 20U;
    result |= positionRd << 16U;
    result |= positionRn << 12U;
    result |= positionRs << 8U;
    result |= const1 << 4U;
    result |= positionRm;

    instruction->encoded = result;
}
