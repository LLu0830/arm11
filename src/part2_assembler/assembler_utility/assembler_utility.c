//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "assembler_utility.h"
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/utility.h"


//rotate left function
uint32_t rotateLeft(uint32_t b, int n) {
    return (b << (unsigned) n) | (b >> (unsigned) (32 - n));
}


bool isLabel(char *string){
    return strchr(string, ':') != NULL;
}

//function to copy string
char *copy_string(char *string){
    if (string == NULL) {
        return NULL;
    }
    char *result = malloc(strlen(string) + 1);
    strcpy(result, string);
    return result;
}

assembler_instruction *instruction_create(void) {
    assembler_instruction *instruction = malloc(sizeof(assembler_instruction));
 //MALLOC CHAR*
    return instruction;
}

void instruction_free(assembler_instruction *instruction) {
    free(instruction->mnemonic);

    if(instruction->arg1 != NULL){
        free(instruction->arg1);
    }

    if(instruction->arg2 != NULL){
        free(instruction->arg2);
    }

    if(instruction->arg3 != NULL){
        free(instruction->arg3);
    }

    if(instruction->arg4 != NULL){
        free(instruction->arg4);
    }

    if(instruction->arg5 != NULL){
        free(instruction->arg4);
    }


    free(instruction);
}

uint32_t getValue(char *string) {
    return (uint32_t) strtol(string + 1, NULL, 0);
}

uint32_t get_shift_type(char *arg){
    switch (arg[0]) {
        case 'l':
            if (arg[2] == 'l') {
                return 0;
            }
            if (arg[2] == 'r') {
                return 1;
            }
            break;
        case 'a':
            return 2;
        case 'r':
           return 3;
        default:
            printf("Invalid shift type\n");
            exit(EXIT_FAILURE);
    }
    return 0;
}

uint32_t getValueFromOp2Optional(char *reg, char *type, char *shift_value){

    uint32_t reg_or_val_flag = 0;
    uint32_t shift_type = 0;
    uint32_t expression_value = getValue(shift_value);
    uint32_t result;
    uint32_t rm = getValue(reg);

    shift_type = get_shift_type(type);

    if (shift_value[0] == '#'){
        reg_or_val_flag = 0;
    }
    else if (shift_value[0] == 'r') {
        reg_or_val_flag = 1;
    }
    else {
        printf("Invalid argument\n");
        exit(EXIT_FAILURE);
    }

    shift_type = shiftLeft(shift_type, 5U);

    if (reg_or_val_flag){
        expression_value = shiftLeft(expression_value, 8U);
    }
    else {
        expression_value = shiftLeft(expression_value, 7U);
    }

    reg_or_val_flag = shiftLeft(reg_or_val_flag, 4U);

    result = expression_value | shift_type | reg_or_val_flag| rm;
    return result;

}


