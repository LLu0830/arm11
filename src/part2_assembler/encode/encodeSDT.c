//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "encodeSDT.h"
#include "encodeDP.h"
#include "../assembler_utility/table.h"

#define MAX_MOV 0xFF;


uint32_t getValue(char *string) {
    char *ptr;
    return (uint32_t) strtol(reg + 1, &ptr, 2);
}

void encodeSDT(assembler_instruction *instruction){

    //??
    uint32_t cond = 1110;
    uint32_t I_bit;
    uint32_t P_bit;
    uint32_t U_bit;
    uint32_t L_bit;
    uint32_t rn;
    uint32_t rd;
    uint32_t offset;

    if (instruction->operationType == ldr) {
        L_bit = 1;
    }
    if (instruction->operationType == str) {
        L_bit = 0;
    }

    if(L_bit && (instruction->arg2 == '=')) {
        if (getValue(instruction->arg2)<MAX_MOV){
            instruction->mnemonic = mov;
            //instruction->arg2 = '#'+strcpy();
            encodeDP(instruction);
        }
        else{

        }

    }

    rd = getValue(instruction->arg1);


}