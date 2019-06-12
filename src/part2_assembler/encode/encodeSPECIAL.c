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

    printf("Entering encodeSPECIAL \n");

    switch (instruction->operationType) {
        case andeq:
            //maybe need to check if operand1,2,3 all = 0;
//            if (!strcmp(instruction->arg1, "r0")
//                && !strcmp(instruction->arg2, "r0")
//                && !strcmp(instruction->arg3, "r0")) {
//                instruction->encoded = 0x0;
//            }
            printf("andeq \n");
            instruction->encoded = 0;
            break;
        case lsl: {
            //lsl gets converted to move instruction: mov Rn, Rn, lsl <#expression>


            printf("calling mov \n");
            free(instruction->mnemonic);
            instruction->mnemonic = copy_string("mov");


            token rn = instruction->arg1;
            printf("arg2 before: %s\n", instruction->arg2);
            char *expression = copy_string(instruction->arg2);
            printf("expression: %s \n", expression);

            free(instruction->arg2);
            free(instruction->arg3);
            free(instruction->arg4);

            instruction->arg1 = rn;
            instruction->arg2 = rn;
            instruction->arg3 = copy_string("lsl");
            printf("expression before being put into arg4: %s \n", expression);
            instruction->arg4 = copy_string(expression);
            printf("expression after arg4: %s \n", expression);

            printf("arg1: %s\n", instruction->arg1);
            printf("arg2: %s\n", instruction->arg2);
            printf("arg3: %s\n", instruction->arg3);
            printf("expression: %s \n", expression);
            printf("arg4: %s\n", instruction->arg4);
            free(expression);


            //encodeDP(instruction);



            encode(instruction, table);

            break;
        }
        default:
            perror("Invalid operation type");
            exit(EXIT_FAILURE);
    }

}
