//
// Created by Rini Banerjee on 2019-05-25.
//


// SUGGESTION: INCLUDE ASSERTIONS TO MAKE SURE N AND START_POS ARE LESS THAN SIZE_OF(B)

#include "utility.h"
#include "state.h"
#include "instruction.h"
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "DefinedTypes.h"


uint32_t get_n_bits(uint32_t b, int start_pos, int number_of_bits) {
    return ((b >> (unsigned int) start_pos) & (unsigned int) (pow(2, number_of_bits) - 1));
}

uint32_t change_bit(uint32_t b, int pos, int val) {
    return ((b & ~(1U << (unsigned int) pos)) | (unsigned int) ((unsigned int) val << (unsigned int) pos));
}


////rotate right by 1
//uint32_t rotateRightOne(uint32_t b) {
//    int rightMostBit = get_n_bits(b, 0, 1);
//    uint32_t newInt = b >> 1U;
//    return change_bit(newInt, 0, rightMostBit);
//}
//
////rotate right by n
//uint32_t rotateRight(uint32_t b, int n) {
//    int newInt = rotateRightOne(b);
//    for (int i = 1; i < n; i++) {
//        newInt = rotateRightOne(newInt);
//    }
//    return newInt;
//}

//better rotate right function
uint32_t rotateRight(uint32_t b, int n) {
    return (b >> n) | (b << (sizeof(uint32_t) - n));
}

//executes logical shift left by n bits
uint32_t shiftLeft(uint32_t b, int n) {
    return b << n;
}

//executes logical shift right by n
uint32_t shiftRight(uint32_t b, int n) {
    return b >> n;
}


//executes arithmetic shift right by n
uint32_t arShiftRight(uint32_t b, int n) {
    uint32_t result;
    if ((int_32) b < 0) {
       result = ~(~b >> n);
    }
    else {
        result = b >> n;
    }
    return result;
}

//executes the shifts
uint32_t shiftRegister(uint32_t b, uint32_t amount, ShiftType shiftType) {
    switch (shiftType) {
        case LSL:
            //logical left (lsl)
            shiftLeft(b, amount);
            break;
        case LSR:
            //logical right (lsr)
            shiftRight(b, amount);
            break;
        case ASR:
            //arithmetic right (asr)
            arShiftRight(b, amount);
            break;
        case ROR:
            //rotate right (ror)
            rotateRight(b, amount);
            break;
        default:
            break;
    }
}


struct stateOfMachine createNewState() {
    struct stateOfMachine state = (struct stateOfMachine *) malloc(sizeof(struct stateOfMahcine *));
    state->instruction_type = (struct instruction_type *) malloc(sizeof(struct instruction_type *));
    return state;
}

//uint32_t negate(uint32_t b) {
//    return (~b) + 1;
//}

uint32_t makeASRmask(int shiftAmount) {
    uint32_t reverseMask = (1U << (unsigned int) (32 - shiftAmount - 1)) - 1;
    return reverseMask ^ 0U;
}




//uint32_t write_one(uint32_t b, int pos) {
//    return (b | 1U << (unsigned int) pos);
//}

