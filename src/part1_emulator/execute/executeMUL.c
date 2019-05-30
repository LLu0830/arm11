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

void executeMUL(uint32_t fetched, struct stateOfMachine *state) {
    uint32_t result;

//    instruction.instructionType = MUL;
// holds the A bit
    uint32_t accumulate = get_n_bits(fetched, 21, 1);
// holds the S bit
    uint32_t scc = get_n_bits(fetched, 20, 1);
// rd,rn,rs,rm it should be a 4-bits address in the array registers, 0-12
    uint32_t rd = get_n_bits(fetched, 16, 4);
    uint32_t rn = get_n_bits(fetched, 12, 4);
    uint32_t rs = get_n_bits(fetched, 8, 4);
    uint32_t rm = get_n_bits(fetched, 0, 4);

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
            setZ(state, 1);
        }

        //get 31bit, if equal to N, unchanged, else update
        uint32_t value = get_n_bits(result, 31, 1);
        setN(state, value);

    }

}
