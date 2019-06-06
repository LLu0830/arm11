//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include "encodeSDT.h"
#include "../assembler_utility/table.h"

int getRegisterAddress(char *reg) {
    
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



    instruction->arg1

}