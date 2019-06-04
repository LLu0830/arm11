//
// Created by Katarina Kulkova on 02.06.2019.
//

#include "encodeMUL.h"
#include "../assembler_utility/table.h"
#include "../assembler_utility/assembler_utility.h"
#include "../../part1_emulator/emulator_utility/utility.h"

void encodeMUL(assembler_instruction *instruction) {
    token *mnemonic = instruction->mnemonic;
    uint32_t encoded = instruction->encoded;
    // change S bit to 0
    encoded = change_bit(&encoded, 20, 0);
    //set condition to 1110
    set_4_bits(&encoded, 28, 0xE);
    // set 16-19(Rd) with operand1
    set_4_bits(&encoded, 16, instruction->arg1->code);
    //set 0-3(Rm) with operand2
    set_4_bits(&encoded, 0, instruction->arg2->code);
    // set 8-11(Rs) with operand3
    set_4_bits(&encoded, 8, instruction->arg3->code);

    switch (mnemonic->name) {
        case "mul":
            // change A bit to 0
            encoded = change_bit(encoded, 21, 0);
            break;
        case "mla":
            // change A bit to 1
            encoded = change_bit(encoded, 21, 1);
            // set 12-15(Rn) with operand4
            set_bits(&encoded, 12, instruction->arg4);
            break;
    }

}