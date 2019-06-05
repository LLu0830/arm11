//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include "encodeSDT.h"
#include "../assembler_utility/table.h"

void encodeSDT(assembler_instruction *instruction){
    uint32_t L_bit;

    if (instruction->operationType == ldr) {
        L_bit = 1;
    }
    if (instruction->operationType == str) {
        L_bit = 0;
    }

}