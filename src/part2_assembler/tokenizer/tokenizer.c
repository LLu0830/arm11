//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "tokenizer.h"
#include "../assembler_utility/table.h"

char *copy_string(char *string){
    char *result = malloc(strlen(string) + 1);
    strcpy(result, string);
    return result;
}

void tokenizer(char *instruction, assembler_instruction *parsed) {

    char* ptr;
    parsed->mnemonic = copy_string(strtok_r(instruction, " ", &ptr));
    parsed->arg1 = copy_string(strtok_r(NULL, ", ", &ptr));
    parsed->arg2 = copy_string(strtok_r(NULL, ", ", &ptr));
    parsed->arg3 = copy_string(strtok_r(NULL, ", ", &ptr));
    parsed->arg4 = copy_string(strtok_r(NULL, ", ", &ptr));

    parsed->type =;
}