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


void decode(struct stateOfMachine state, uint32_t fetched, instruction_type instruction) {
    // check condition first
    // get cond 4bits
    instruction.conditionType = 0xf & (fetched >> 28);
    if (!checkCondition(state, instruction.conditionType)) {

        //instruction is ignored, may need another function
    }


    //what type of instruction it is..
    //store the instruction in corresponding instruction
    //and execute

    //branch
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
    } else {
        decodeMUL(instruction, fetched);
    }



    execute(instruction, state);

}


void decodeMUL(instruction_type instruction, uint32_t fetched) {
//    (Rini) Multiply doesn't exist any more? This needs to be changed
    instruction.instructionType = Multiply;
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


void decodeDP(instruction_type instruction, uint32_t fetched) {

}

void decodeSDT(instruction_type instruction, uint32_t fetched) {}

void decodeBR(instruction_type instruction, uint32_t fetched) {}

