//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>
#include "executeDP.h"
#include "state.h"
#include "utility.h"
#include <stdio.h>
#include <stdbool.h>


void executeDP(struct registers ARM11_registers, uint32_t b) {
    uint32_t i = get_n_bits(b, 25, 1);
    uint32_t opCode = get_n_bits(b, 21, 4);
    uint32_t s = get_n_bits(b, 20, 1);
    uint32_t rn = get_n_bits(b, 16, 4);
    uint32_t rd = get_n_bits(b, 12, 4);
    uint32_t op2 = get_n_bits(b, 0, 12);

    uint32_t result;

    if (i == 1) {
        uint32_t rotateAmount = get_n_bits(op2, 8, 4);
        uint32_t imm = get_n_bits(op2, 0, 8);
        result = rotateRight(imm, rotateAmount);
    } else {
        uint32_t valueInRM = get_n_bits(op2, 0, 4);
        uint32_t shift = get_n_bits(op2, 4, 8);
        uint32_t lastBit = get_n_bits(op2, 4, 1);
        if (lastBit == 0) {
            uint32_t shiftAmount = get_n_bits(op2, 7, 5);
            if (shiftAmount == 0) {
                result = valueInRM;
                break;
            }
            uint32_t shiftCode = get_n_bits(op2, 5, 2);
            int carryBit;
            if (shiftCode == 0) {
                carryBit = get_n_bits(valueInRM, 32 - shiftAmount, 1);
            } else {
                carryBit = get_n_bits(valueInRM, shiftAmount - 1, 1);
            }
            switch (shiftCode) {
                case 0:
                    result = valueInRM << shiftAmount;
                    break;
                case 1:
                    result = valueInRM >> shiftAmount;
                    break;
                case 2:
                    int bit31 = get_n_bits(valueInRM, 31, 0);
                    break;
                case 3:

                    break;
                default:
                    break;
            }

        }
    }


}