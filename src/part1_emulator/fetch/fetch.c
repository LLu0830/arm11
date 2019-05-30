//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "part1_emulator/emulator_utility/state.h"
#include "fetch.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/emulate/pipeline.h"
#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulator_utility/DefinedTypes.h"

//fetches instruction from memory

// (Rini) confused - are we allowed to just access array elements from mem even though it is of the type uint32_t * (a pointer)?



//uint32_t fetch(struct stateOfMachine ARM11) {
//    uint8_t *mem = ARM11.mem;
//    uint32_t f = 0;
//    uint32_t PC = (int) ARM11.registers[15];
//    for (int i = 0; i < 4; i++) {
//        f |= ((uint32_t) * (mem + PC + i) << (i * 8));
//    }
//    return f;
//}

uint32_t fetch(struct stateOfMachine *ARM11, uint32_t address) {
    //uint32_t result = *((uint32_t * )(state->mem + address));
    //return result;
    return *((uint32_t * )(ARM11->mem + address));
}