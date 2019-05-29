//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "state.h"
#include "decode.h"


#include "utility.h"
#include "instruction.h"
#include "DefinedTypes.h"
#include "execute.h"
//Add decode function
//add ARM11.registers.decoded=output


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
    }
    return false;
}


void decode(struct stateOfMachine state, uint32_t fetched, instruction_type instruction) {
    // check condition first
    // get cond 4bits
    instruction.conditionType = 0xf & (fetched >> 28);
    //what type of instruction it is..
    //store the instruction in corresponding instruction
    //and execute

    //BR
    uint32_t branchCheck = fetched >> 27 & 0x1;
    if (branchCheck != 0) {
        decodeBR(instruction, fetched);
    }

    //SDT
    uint32_t SDTCheck = fetched >> 26 & 0x1;
    if (SDTCheck != 0) {
        decodeSDT(instruction, fetched);
    }

    //MUL & DP
    uint32_t bit4Check = fetched >> 4 & 0x1;
    if (bit4Check == 0) {
        decodeDP(instruction, fetched);
        //instruction.instructionType = DP;
    } else {
        decodeMUL(instruction, fetched);
    }

    //HLT
    if (fetched == 0) {
        decodeHLT(instruction, fetched);
    }

    execute(instruction, state);
}




void decodeMUL(instruction_type instruction, uint32_t fetched) {
    instruction.instructionType = MUL;
// holds the A bit
    instruction.accumulate = 0x1 & fetched >> 21;
// holds the S bit
    instruction.scc = 0x1 & fetched >> 20;
// rd,rn,rs,rm it should be a 4-bits address in the array registers, 0-12
    instruction.rd = fetched >> 16 & 0xf;
    instruction.rn = fetched >> 12 & 0xf;
    instruction.rs = fetched >> 8 & 0xf;
    instruction.rm = fetched & 0xf;
}


void decodeDP(instruction_type instruction, uint32_t b) {
    // Jason says can keep it like in the executeDP file.
    // May ignore the following or change a few lines in executeDP

    instruction.instructionType = DP;
//    instruction.conditionType = get_n_bits(b, 28, 4);
    instruction.immediateOperand = get_n_bits(b, 25, 1);
    instruction.operationType = get_n_bits(b, 21, 4);
    instruction.scc = get_n_bits(b, 20, 1);
    instruction.rn = get_n_bits(b, 16, 4);
    instruction.rd = get_n_bits(b, 12, 4);
    instruction.offsets_or_operand2 = get_n_bits(b, 0, 12);
}

void decodeSDT(instruction_type instruction, uint32_t fetched) {
    instruction.instructionType = SDT;
    instruction.immediateOffset = get_n_bits(fetched, 25, 1);
    instruction.Pre_Post = get_n_bits(fetched, 24, 1);
    instruction.upBit = get_n_bits(fetched, 23, 1);
    instruction.storeBit = get_n_bits(fetched, 20, 1);
    instruction.rn = get_n_bits(fetched, 16, 4); //base register
    instruction.rd = get_n_bits(fetched, 12, 4);  //source/destination register
    instruction.offsets_or_operand2 = get_n_bits(fetched, 0, 12);

}


void decodeBR(instruction_type instruction, uint32_t b) {
    instruction.instructionType = BR;
//    instruction.conditionType = get_n_bits(b, 28, 4);
    instruction.offsets_or_operand2 = get_n_bits(b, 0, 23);
}

void decodeHLT(instruction_type instruction, uint32_t fetched) {
    instruction.instructionType = HLT;
}