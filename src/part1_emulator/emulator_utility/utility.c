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

void change_bit(uint32_t b, int pos, int val) {
    uint32_t new_b = ((b & ~(1U << (unsigned int) pos)) | (unsigned int) ((unsigned int) val << (unsigned int) pos));
    b = new_b;
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
    if ((uint32_t) b < 0) {
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
            printf("Unrecognized shift type");
            break;
    }
}

uint32_t makeASRmask(int shiftAmount) {
    uint32_t reverseMask = (1U << (unsigned int) (32 - shiftAmount - 1)) - 1;
    return reverseMask ^ 0U;
}

bool checkCondition(struct stateOfMachine state, Cond condition) {
    //check condition fist
    uint32_t CPSRflag = state.registers[CPSRPosition];
    uint32_t VMasked = (CPSRflag >> 28U) & (unsigned) V;
    uint32_t NMasked = (CPSRflag >> 28U) & (unsigned) N;
    uint32_t ZMasked = (CPSRflag >> 28U) & (unsigned) Z;
    uint32_t CMasked = (CPSRflag >> 28U) & (unsigned) C;

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
        default:
            break;
    }
    return false;
}

InstructionType get_type(uint32_t fetched) {
    // check condition first
    // get cond 4bits
//    instruction.conditionType = 0xf & (fetched >> 28U);
    //what type of instruction it is..
    //store the instruction in corresponding instruction
    //and execute

    //HLT
    if (fetched == 0) {
        return HLT;
    }

    uint8_t cond = get_n_bits(fetched, 28, 4);


    //BR
    uint32_t branchCheck = (fetched >> 27) & 0x1;
    if (branchCheck != 0) {
        return BR;
    }

    //SDT
    uint32_t SDTCheck = (fetched >> 26) & 0x1;
    if (SDTCheck != 0) {
        return SDT;
    }

    //MUL & DP
    uint32_t bit4Check = (fetched >> 4) & 0x1;
    if (bit4Check == 0) {
        return DP;
    }
    //is this really okay???
    else {
        return MUL;
    }
}

//setter functions for CPSR flags
//may be wrong, since I am confused about little and big Endian in the spec
void setN(struct stateOfMachine ARM11, uint32_t value){
    uint32_t result = ARM11.registers[CPSRPosition];
    change_bit(result, 31, value);
    ARM11.registers[CPSRPosition] = result;
}

void setZ(struct stateOfMachine ARM11, uint32_t value){
    uint32_t result = ARM11.registers[CPSRPosition];
    change_bit(result, 30, value);
    ARM11.registers[CPSRPosition] = result;
}

void setC(struct stateOfMachine ARM11, uint32_t value){
    uint32_t result = ARM11.registers[CPSRPosition];
    change_bit(result, 29, value);
    ARM11.registers[CPSRPosition] = result;
}

void setV(struct stateOfMachine ARM11, uint32_t value){
    uint32_t result = ARM11.registers[CPSRPosition];
    change_bit(result, 28, value);
    ARM11.registers[CPSRPosition] = result;
}






