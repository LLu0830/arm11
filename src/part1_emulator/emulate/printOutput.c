//
// Created by mw6118 on 30/05/19.
//

#include "../emulator_utility/state.h"
#include "printOutput.h"

#include <stdio.h>

void printOut(struct stateOfMachine *state) {
    printf("Registers:\n");

    for (int i = 0; i < 13; i++) {
        printf("$%3d: %11d (0x%08X)\n", i, (int) state->registers[i], state->registers[i]);
    }

    printf("PC  : %11d (0x%08X)\n", (int) state->registers[PCPosition], state->registers[PCPosition]);
    printf("CPSR: %11d (0x%08X)\n", (int) state->registers[CPSRPosition], state->registers[CPSRPosition]);

    printf("Non-zero memory:\n");

    for (int curr = 0; curr < numOfAddresses; curr = curr + 4) {
        uint32_t f = 0;
        for (int i = 0; i < 4; i++) {
            f |= ((uint32_t) *(state->mem + curr + i)) << (i * 8);
        }
        if (f == 0) {
        } else {
            printf("0x%08x: 0x%08x\n", curr, f);
        }
    }

}
