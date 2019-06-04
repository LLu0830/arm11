//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <string.h>
#include "encodeMUL.h"
#include "../assembler_utility/table.h"
#include "../assembler_utility/assembler_utility.h"
#include "../../part1_emulator/emulator_utility/utility.h"

void encodeMUL(assembler_instruction *instruction) {
    token mnemonic = instruction->mnemonic;
    uint32_t encoded = instruction->encoded;
    // change S bit to 0
    instruction->encoded = change_bit(encoded, 20, 0);

    //set condition to 1110
    set_4_bits(&instruction->encoded, 28, 0xE);

    // set 16-19(Rd) with operand1
    token rd = instruction->arg1;
    uint32_t positionRd  = (unsigned int) *(rd + 1) - '0';
//    set_4_bits(&instruction->encoded, 16, positionRd);

    //set 0-3(Rm) with operand2
    token rm =instruction->arg2;
    uint32_t positionRm  = (unsigned int) *(rm + 1) - '0';
//    set_4_bits(&instruction->encoded, 0, );

    // set 8-11(Rs) with operand3
    token rs = instruction->arg3;
    uint32_t positionRs  = (unsigned int) *(rs + 1) - '0';

//    set_4_bits(&instruction->encoded, 8, instruction->arg3);

    uint32_t positionRn;
    switch (*(mnemonic + 1)) {
        case 'u':
            // change A bit to 0
            encoded = change_bit(encoded, 21, 0);

            break;
        case 'l':
            // change A bit to 1
            encoded = change_bit(encoded, 21, 1);
            // set 12-15(Rn) with operand4

            break;
    }

}