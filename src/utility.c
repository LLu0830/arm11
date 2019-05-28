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



uint32_t get_n_bits(uint32_t b, int start_pos, int number_of_bits) {
    return ((b >> (unsigned int) start_pos) & (unsigned int) (pow(2, number_of_bits) - 1));
}

uint32_t change_bit(uint32_t b, int pos, int val) {
    return ((b & ~(1U << (unsigned int) pos)) | (unsigned int) ((unsigned int) val << (unsigned int) pos));
}


//rotate right by 1
uint32_t rotateRightOne(uint32_t b) {
    int rightMostBit = get_n_bits(b, 0, 1);
    uint32_t newInt = b >> 1U;
    return change_bit(newInt, 0, rightMostBit);
}

//rotate right by n
uint32_t rotateRight(uint32_t b, int n) {
    int newInt = rotateRightOne(b);
    for (int i = 1; i < n; i++) {
        newInt = rotateRightOne(newInt);
    }
    return newInt;
}

//functions below rely on rotate to work correctly, I did not check it
//please have a look at them:
//they are probably wrong :(
//also there is probably a more efficient way to do it
//(Katarina)

//executes logical shift left by n bits
uint32_t shiftLeft(uint32_t b, int n) {
    uint32_t result = rotateRight(b, sizeof(uint32_t) - n - 1);
    for (int i = 0; i < n; i++) {
        result = change_bit(result, i, 0);
    }
    return result;
}

//executes logical shift right by n
uint32_t shiftRight(uint32_t b, int n) {
    uint32_t result = rotateRight(b, n);
    for (int i = sizeof(uint32_t) - 1; i > sizeof(uint32_t) - n - 1; i--) {
        result = change_bit(result, i, 0);
    }
    return result;
}


//executes arithmetic shift right by n
uint32_t arShiftRight(uint32_t b, int n) {
    int sign = get_n_bits(b, sizeof(uint32_t) - 1, 1);
    uint32_t result = rotateRight(b, n);
    for (int i = sizeof(uint32_t) - 1; i > sizeof(uint32_t) - n - 1; i--) {
        result = change_bit(result, i, sign);
    }
    return result;

}

//executes the shifts
//I am not sure this is right, especially the switch cases???
uint32_t shiftRegister(uint32_t b, uint32_t amount, uint32_t shiftType) {
    switch (shiftType) {
        case 00:
            //logical left (lsl)
            //needs casting or not??
            shiftLeft(b, (int) amount);
            break;
        case 01:
            //logical right (lsr)
            //casting??
            shiftRight(b, (int) amount);
            break;
        case 10:
            //arithmetic right (asr)
            //casting???
            arShiftRight(b, (int) amount);
            break;
        case 11:
            //rotate right (ror)
            //amount is of type uint32_t, but rotateRight requires int - problem???
            //is there need for casting???
            rotateRight(b, (int) amount);
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

uint32_t negate(uint32_t b) {
    return (~b) + 1;
}

uint32_t makeASRmask(int shiftAmount) {
    uint32_t reverseMask = (1U << (unsigned int) (32 - shiftAmount - 1)) - 1;
    return reverseMask ^ 0U;
}




//uint32_t write_one(uint32_t b, int pos) {
//    return (b | 1U << (unsigned int) pos);
//}

