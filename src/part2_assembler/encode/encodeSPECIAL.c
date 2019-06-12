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

    printf("Entering encodeSPECIAL");

    switch (instruction->operationType) {
        case andeq:
            //maybe need to check if operand1,2,3 all = 0;
//            if (!strcmp(instruction->arg1, "r0")
//                && !strcmp(instruction->arg2, "r0")
//                && !strcmp(instruction->arg3, "r0")) {
//                instruction->encoded = 0x0;
//            }
            printf("andeq");
            instruction->encoded = 0;
            break;
        case lsl: {
            //lsl gets converted to move instruction: mov Rn, Rn, lsl <#expression>


            free(instruction->mnemonic);
            instruction->mnemonic = copy_string("mov");

            char *mov_arg2 = copy_string(instruction->arg1);
            char *mov_arg4 = copy_string(instruction->arg2);

            free(instruction->arg2);
            free(instruction->arg3);
            free(instruction->arg3);

            instruction->arg2 = copy_string(mov_arg2);
            instruction->arg3 = copy_string("lsl");
            instruction->arg4 = copy_string(mov_arg4);

            free(mov_arg2);
            free(mov_arg4);

            encodeDP(instruction);
            break;
        }
        default:
            perror("Invalid operation type");
            exit(EXIT_FAILURE);
    }



}
