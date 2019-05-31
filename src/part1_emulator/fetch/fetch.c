//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "../emulator_utility/state.h"
#include "fetch.h"
#include "../emulator_utility/utility.h"
#include "../emulate/pipeline.h"
#include "../emulator_utility/instruction.h"
#include "../emulator_utility/DefinedTypes.h"

//fetches instruction from memory

// (Rini) confused - are we allowed to just access array elements from mem even though it is of the type uint32_t * (a pointer)?



//uint32_t fetch(struct stateOfMachine ARM11) {
//    uint32_t f = 0;
//    uint32_t PC = (int) ARM11.registers[15];
//    for (int i = 0; i < 4; i++) {
//        f |= ((uint32_t) * (ARM11.mem + PC + i) << (i * 8));
//    }
//    return f;
//}

uint32_t fetch(struct stateOfMachine *ARM11, uint32_t address) {
    return *((uint32_t * )(ARM11->mem + address));
}