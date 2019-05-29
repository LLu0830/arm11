//
// Created by MANSHU WANG on 5/24/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>


#include "executeMUL.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/emulator_utility/DefinedTypes.h"
#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulator_utility/state.h"


// (Rini) This function is throwing an error ("conflicting types for 'executeMUL') - not sure why

void executeMUL(uint32_t fetched, struct stateOfMachine state) {
    uint32_t result;

//    instruction.instructionType = MUL;
// holds the A bit
    bool accumulate = get_n_bits(fetched, 21, 1);
// holds the S bit
    bool scc = get_n_bits(fetched, 20, 1);
// rd,rn,rs,rm it should be a 4-bits address in the array registers, 0-12
    register_address rd = get_n_bits(fetched, 16, 4);
    register_address rn = get_n_bits(fetched, 12, 4);
    register_address rs = get_n_bits(fetched, 8, 4);
    register_address rm = get_n_bits(fetched, 0, 4);

    uint32_t valueRn = state.registers[(int) rn];
    uint32_t valueRm = state.registers[(int) rm];
    uint32_t valueRs = state.registers[(int) rs];

    if (accumulate) {
        //Accumulate is set, performs a multiply and accumulate
        result = valueRm * valueRs + valueRn;
    } else {
        // performs only multiply
        result = valueRm * valueRs;
    }

    state.registers[(int) rd] = result;

    if (scc) {
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