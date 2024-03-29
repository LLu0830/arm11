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

void encodeSPECIAL(assembler_instruction *instruction, label_address_list *table) {

    switch (instruction->operationType) {
        case ANDEQ:
            //need to check if operand1,2,3 all = 0;
            if (!strcmp(instruction->arg1, "r0")
                && !strcmp(instruction->arg2, "r0")
                && !strcmp(instruction->arg3, "r0")) {
                instruction->encoded = 0x0;
            }
            break;
        case lsl: {
            //lsl gets converted to move instruction: mov Rn, Rn, lsl <#expression>
            free(instruction->mnemonic);
            instruction->mnemonic = copy_string("mov");


            token rn = instruction->arg1;
            char *expression = copy_string(instruction->arg2);

            free(instruction->arg2);
            free(instruction->arg3);
            free(instruction->arg4);

            instruction->arg1 = copy_string(rn);
            instruction->arg2 = copy_string(rn);
            instruction->arg3 = copy_string("lsl");
            instruction->arg4 = copy_string(expression);

            free(expression);
            free(rn);

            instruction->operationType = MOV;

            encodeDP(instruction);

            break;
        }
        default:
            perror("Invalid operation type");
            exit(EXIT_FAILURE);
    }

}
