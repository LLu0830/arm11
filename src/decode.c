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

void checkCondition(struct stateOfMachine state, instruction_type instruction) {
    //check condition fist
    uint32_t CPSRflag = state.registers[CPSRPosition];
    Cond condition = 0xf & (fetched >> 28);
    switch condition
    {
        case EQ: {
            if ((0x1 << 30 & CPSRflag) >> 30) &0x1 == 1){
                execute(instruction.instructionType, state);
            }
        }

        case NE:
        case GE:
        case LT:
        case GT:
        case LE:
        case Al:
        //ignored
        //if not satisfy the condition also we also need a termination
    }

    //else terminate here
}


void decode(struct stateOfMachine state, uint32_t fetched) {
    //what type of instruction it is..
    //store the instruction in corresponding instruction
    // and execute
}


void decodeMUL(instruction_type instruction, uint32_t fetched, struct stateOfMachine state) {
    // get cond 4bits

    instruction.conditionType = 0xf & (fetched >> 28);

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


void decodeDP(instruction_type instruction, uint32_t fetched){}
void decodeSGT(instruction_type instruction, uint32_t fetched){}
void decodeB(instruction_type instruction, uint32_t fetched){}

