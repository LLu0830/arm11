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


//rotate left function
uint32_t rotateLeft(uint32_t b, int n) {
    return (b << (unsigned) n) | (b >> (unsigned) (32 - n));
}

//uint32_t rotateLeftNtimes(uint32_t b, int n) {
//    for (int i = 0; i < n; i++) {
//        b = rotateLeft(b, n);
//    }
//    return b;
//}

//static bool is_label(char *instruction) {
//    return instruction[strlen(instruction) - 1] == ':';
//}

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

    free(instruction);
}

uint32_t getValue(char *string) {
    return (uint32_t) strtol(string + 1, NULL, 0);
}



