//
// Created by mw6118 on 30/05/19.
//

#include "../emulator_utility/state.h"
#include "../emulator_utility/utility.h"
#include "printOutput.h"

#include <stdio.h>

// flips the instruction, so that bit #n becomes bit #(31 - n)
uint32_t flip(uint32_t f) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i = i + 8) {
        result = (result << 8U) | get_n_bits(f, i, 8);

    }
    return result;
}


// prints values of registers
void printOut(struct stateOfMachine *state) {
    printf("Registers:\n");

    for (int i = 0; i < 13; i++) {
        printf("$%-3d: %10d (0x%08x)\n", i, (int) state->registers[i], state->registers[i]);
    }

    printf("PC  : %10d (0x%08x)\n", (int) state->registers[PCPosition], state->registers[PCPosition]);
    printf("CPSR: %10d (0x%08x)\n", (int) state->registers[CPSRPosition], state->registers[CPSRPosition]);

    printf("Non-zero memory:\n");

    for (int curr = 0; curr < numOfAddresses; curr = curr + 4) {
        uint32_t f = *((uint32_t *) (state->mem + curr)); // this is fetch

        if (f != 0) {
            f = flip(f);
            printf("0x%08x: 0x%08x\n", curr, f);
        }

    }

}
