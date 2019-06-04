//
// Created by MANSHU WANG on 6/4/2019.
//
#include "encodeMUL.h"
#include "encodeSPECIAL.c"
#include "../assembler_utility/table.h"
#include "../assembler_utility/assembler_utility.h"

void encodeSPECIAL(assembler_instruction *instruction) {
    token mnemonic = instruction->mnemonic;
    uint32_t encoded = instruction->encoded;

    switch (mnemonic->name) {
        case "andeq":
            //maybe need to check if operand1,2,3 all = 0;
            if (instruction->arg1->code == 0
                && instruction->arg2->code == 0
                && instruction->arg3->code == 0) {
                set_bits(&encoded, 0, 0x0);
            }
        case "lsl":
            // case DP: Operand2 is a register, shifted by a constant amount
            //set opcode to mov
            set_bits(&encoded, 21, 0xd);
            //set s bit to 0
            set_bits(&encoded, 20, 0);
            //cond field set to 1110
            set_bits(&encoded, 28, 0xe);
            //set i bit to 0
            set_bits(&encoded, 25, 0);
            //

    }
}
