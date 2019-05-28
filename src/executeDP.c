//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>
#include "executeDP.h"
#include "state.h"
#include "utility.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "DefinedTypes.h"

//uint32_t getValFromOp2(uint32_t op2, uint32_t i) {
//    uint32_t result = 0;
//    if (i == 1) {
//        uint32_t rotateAmount = get_n_bits(op2, 8, 4);
//        uint32_t imm = get_n_bits(op2, 0, 8);
//        result = rotateRight(imm, rotateAmount);
//    } else {
//        uint32_t valueInRM = get_n_bits(op2, 0, 4);
//        uint32_t shift = get_n_bits(op2, 4, 8);
//        uint32_t lastBit = get_n_bits(op2, 4, 1);
//        if (lastBit == 0) {
//            uint32_t shiftAmount = get_n_bits(op2, 7, 5);
//            int carryBit;
//            if (shiftAmount == 0) {
//                result = valueInRM;
//                carryBit = 0;
//            } else if (shiftAmount > 32) {
//                result = 0;
//                carryBit = 0;
//            } else {
//                uint32_t shiftCode = get_n_bits(op2, 5, 2);
//
//                if (shiftCode == 0) {
//                    carryBit = get_n_bits(valueInRM, 32 - shiftAmount, 1);
//                } else {
//                    carryBit = get_n_bits(valueInRM, shiftAmount - 1, 1);
//                }
//                switch (shiftCode) {
//                    case 0:
//                        result = valueInRM << shiftAmount;
//                        break;
//                    case 1:
//                        result = valueInRM >> shiftAmount;
//                        break;
//                    case 2: {
//                        int bit31 = get_n_bits(valueInRM, 31, 0);
//                        result = valueInRM >> shiftAmount;
//                        if (bit31 != 0) {
//                            uint32_t mask = makeASRmask(shiftAmount);
//                            result = result | mask;
//                        }
//                        break;
//                    }
//                    case 3:
//                        result = rotateRight(valueInRM, shiftAmount);
//                        break;
//                    default:
//                        break;
//                }
//            }
//        }
//    }
//    return result;
//}

void executeDP(struct stateOfMachine ARM11_registers, uint32_t instruction) {
//    PUT INSIDE DECODE.C
    uint32_t i = get_n_bits(instruction, 25, 1);
    uint32_t opCode = get_n_bits(instruction, 21, 4);
    uint32_t s = get_n_bits(instruction, 20, 1);
    uint32_t rn = get_n_bits(instruction, 16, 4);
    uint32_t rd = get_n_bits(instruction, 12, 4);
    uint32_t op2 = get_n_bits(instruction, 0, 12);

    uint32_t result = 0;
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
            int carryBit;
            if (shiftAmount == 0) {
                result = valueInRM;
                carryBit = 0;
            } else if (shiftAmount > 32) {
                result = 0;
                carryBit = 0;
            } else {
                uint32_t shiftCode = get_n_bits(op2, 5, 2);

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
                    case 2: {
                        int bit31 = get_n_bits(valueInRM, 31, 0);
                        result = valueInRM >> shiftAmount;
                        if (bit31 != 0) {
                            uint32_t mask = makeASRmask(shiftAmount);
                            result = result | mask;
                        }
                        break;
                    }
                    case 3:
                        result = rotateRight(valueInRM, shiftAmount);
                        break;
                    default:
                        break;
                }
            }
        }
    }



}