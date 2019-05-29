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
            return shiftLeft(b, amount);
        case LSR:
            //logical right (lsr)
            return shiftRight(b, amount);
        case ASR:
            //arithmetic right (asr)
            return arShiftRight(b, amount);
        case ROR:
            //rotate right (ror)
            return rotateRight(b, amount);
        default:
            printf('Unrecognized shift type');
            break;
    }
}

struct stateOfMachine createNewState() {
    struct stateOfMachine state = (struct stateOfMachine *) malloc(sizeof(struct stateOfMahcine *));
    state->instruction_type = (struct instruction_type *) malloc(sizeof(struct instruction_type *));
    return state;
}

uint32_t makeASRmask(int shiftAmount) {
    uint32_t reverseMask = (1U << (unsigned int) (32 - shiftAmount - 1)) - 1;
    return reverseMask ^ 0U;
}


bool checkCondition(struct stateOfMachine state, Cond condition) {
    //check condition fist
    uint32_t CPSRflag = state.registers[CPSRPosition];
    uint32_t VMasked = (CPSRflag >> 28) & V;
    uint32_t NMasked = (CPSRflag >> 28) & N;
    uint32_t ZMasked = (CPSRflag >> 28) & Z;
    uint32_t CMasked = (CPSRflag >> 28) & C;

    bool NEqualsV = (VMasked >> 3) == NMasked;
    switch (condition) {
        case EQ:
            if (ZMasked != 0) {
                return true;
            }
            break;
        case NE:
            if (ZMasked == 0) {
                return true;
            }
            break;
        case GE:
            if (NEqualsV) {
                return true;
            }
            break;
        case LT:
            if (!NEqualsV) {
                return true;
            }
            break;
        case GT:
            if (ZMasked == 0 && NEqualsV) {
                return true;
            }
            break;
        case LE:
            if ((ZMasked != 0) || !NEqualsV) {
                return true;
            }
            break;
    }
    return false;
}



//uint32_t write_one(uint32_t b, int pos) {
//    return (b | 1U << (unsigned int) pos);
//}

