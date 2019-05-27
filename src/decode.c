//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "registers.h"
#include "memory.h"
#include "decode.h"
#include "utility.h"

#include "state.h"
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
        case NE:
            if (ZMasked == 0) {
                return true;
            }
        case GE:
            if (NEqualsV) {
                return true;
            }
        case LT:
            if (!NEqualsV) {
                return true;
            }
        case GT:
            if (ZMasked == 0 && NEqualsV){
                return true;
            }
        case LE:
            if ((ZMasked != 0) || !NEqualsV) {
                return true;
            }
    }
    return false;
}


void decode(struct stateOfMachine state, uint32_t fetched, instruction_type instruction) {
    // check condition first
    // get cond 4bits
    instruction.conditionType = 0xf & (fetched >> 28);
    if (!checkCondition(state, instruction.conditionType)) {

        //terminate
    }
    //what type of instruction it is..
    //store the instruction in corresponding instruction
    // and execute

    execute(instruction, state);

}


void decodeMUL(instruction_type instruction, uint32_t fetched, struct stateOfMachine state) {
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
    checkCondition(state, instruction)
}


void decodeDP(instruction_type instruction, uint32_t fetched) {}

void decodeSGT(instruction_type instruction, uint32_t fetched) {}

void decodeB(instruction_type instruction, uint32_t fetched) {}

