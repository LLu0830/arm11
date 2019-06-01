//
// Created by MANSHU WANG on 5/24/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>


#include "executeMUL.h"
#include "../emulator_utility/utility.h"
#include "../emulator_utility/DefinedTypes.h"
#include "../emulator_utility/instruction.h"
#include "../emulator_utility/state.h"

void executeMUL(Instruction instruction, struct stateOfMachine *state) {

    uint32_t result;

//    Instruction.instructionType = MUL;
// holds the A bit
    bool accumulate = instruction.accumulate;
// holds the S bit
    bool scc = instruction.scc;
// rd,rn,rs,rm it should be a 4-bits address in the array registers, 0-12
    register_address rd = instruction.rd;
    register_address rn = instruction.rn;
    register_address rs = instruction.rs;
    register_address rm = instruction.rm;


    uint32_t valueRn = state->registers[rn];
    uint32_t valueRm = state->registers[rm];
    uint32_t valueRs = state->registers[rs];

    if (accumulate) {
        //Accumulate is set, performs a multiply and accumulate
        result = valueRm * valueRs + valueRn;
    } else {
        // performs only multiply
        result = valueRm * valueRs;
    }

    state->registers[rd] = result;


    if (scc) {
        // update N,Z flag in CPSR
        // N - the 31st bit of the result   Z - only if the result is zero
        if (result == 0) {
            state->registers[CPSRPosition] = (Z << 28) ^ (*state).registers[CPSRPosition];
        }

        //get 31bit, if equal to N, unchange // else update

        if ((result >> 31) != (state->registers[CPSRPosition] >> 31)) {
            state->registers[CPSRPosition] = (N << 28) ^ state->registers[CPSRPosition];

        }


    }
}
