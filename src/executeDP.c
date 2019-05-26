//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>
#include "executeDP.h"
#include "registers.h"
#include "utility.h"
#include <stdio.h>
#include "memory.h"


// using utility function

void executeDP(struct registers ARM11_registers, uint32_t b) {
    uint32_t i = get_n_bits(b, 25, 1);
    uint32_t opCode = get_n_bits(b, 21, 4);
    uint32_t s = get_n_bits(b, 20, 1);
    uint32_t rn = get_n_bits(b, 16, 4);
    uint32_t rd = get_n_bits(b, 12, 4);
    uint32_t op2 = get_n_bits(b, 0, 11);

    uint32_t result;
    if (i == 1) {
        uint32_t rotateAmount = get_n_bits(op2, 8, 4);
        uint32_t imm = get_n_bits(op2, 0, 8);
        result = rotateRight(imm, rotateAmount);
    } else {

    }
}