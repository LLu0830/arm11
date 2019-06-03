//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "../emulator_utility/state.h"
#include "fetch.h"


//Fetches next instruction from memory
uint32_t fetch(struct stateOfMachine *ARM11) {
    uint32_t f = 0;
    uint32_t PC = (int) ARM11->registers[15];
    for (int i = 0; i < 4; i++) {
        f |= ((uint32_t) * (ARM11->mem + PC + i)) << (i * 8);
    }
    return f;
}
