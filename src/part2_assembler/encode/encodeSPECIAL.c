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
#include "encodeDP.h"

void encodeSPECIAL(assembler_instruction *instruction) {

    Mnemonic type = instruction->operationType;

    //halt instruction - returns zero
    if (type == andeq) {
        instruction->encoded = 0x00000000;
    }

    //lsl gets converted to move instruction: mov Rn, Rn, lsl <#expression>
    else if (type == lsl) {

        instruction->mnemonic = copy_string("mov");

        char* mov_arg2 = copy_string(instruction->arg1);
        char* mov_arg4 = copy_string(instruction->arg2);

        instruction->arg2 = copy_string(mov_arg2);
        instruction->arg3 = copy_string("lsl");
        instruction->arg4 = copy_string(mov_arg4);

        free(mov_arg2);
        free(mov_arg4);

        encodeDP(instruction);
    }

    //error message
    else {
        perror("Invalid operation type");
        exit(EXIT_FAILURE);
    }

}

