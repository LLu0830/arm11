//
// Created by MANSHU WANG on 5/24/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>


#include "executeMUL.h"
#include "utility.h"
#include "DefinedTypes.h"
#include "instruction.h"
#include "state.h"


// (Rini) This function is throwing an error ("conflicting types for 'executeMUL') - not sure why

void executeMUL(instruction_type instruction, struct stateOfMachine state) {
    uint32_t result;
/**
    int positionRn = (int)(instruction.rn);
    int positionRm = (int)(instruction.rm);
    int positionRs = (int)(instruction.rs);
    int positionRd = (int)(instruction.rd);
*/
    uint32_t valueRn = state.registers[(int) (instruction.rn)];
    uint32_t valueRm = state.registers[(int) (instruction.rm)];
    uint32_t valueRs = state.registers[(int) (instruction.rs)];

    if (instruction.accumulate) {
        //Accumulate is set, performs a multiply and accumulate
        result = valueRm * valueRs + valueRn;
    } else {
        // performs only multiply
        result = valueRm * valueRs;
    }

    state.registers[(int) (instruction.rd)] = result;

    if (instruction.scc) {
        // update N,Z flag in CPSR
        // N - the 31st bit of the result   Z - only if the result is zero
        if (result == 0) {
            state.registers[CPSRPosition] = (Z << 28) ^ state.registers[CPSRPosition];
        }

        //get 31bit, if equal to N, unchange // else update
        if ((result >> 31) != (state.registers[CPSRPosition] >> 31)) {
            state.registers[CPSRPosition] = (N << 28) ^ state.registers[CPSRPosition];
        }

    }


}

/**
int binaryToDecimal(uint8_t binary_val) {
    int decimal_val = 0;
    int base = 1;
    int result = 0;
    uint8_t mask = 0x1;

    while (binary_val > 0) {
        if (mask & binary_val == 1) {
            decimal_val += base;
        }
        binary_val = binary_val >> 1;
        base *= 2;
    }

}

*/