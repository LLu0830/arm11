//
// Created by mw6118 on 30/05/19.
//

#include "../emulator_utility/state.h"
#include "printOutput.h"

#include <stdio.h>

void printOut(struct stateOfMachine state) {
    printf("Registers:\n");

    for (int i = 0; i < 13; i++) {
        printf("$%d  : %d (%x)\n", i, (int)state.registers[i], (uint32_t) state.registers[i]);
    }

    printf("PC  : %d (%x)\n", (int) state.registers[PCPosition], (uint32_t) state.registers[PCPosition]);
    printf("CPSR: %d (%x)\n", (int) state.registers[CPSRPosition], (uint32_t) state.registers[CPSRPosition]);

}
