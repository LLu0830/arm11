//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "state.h"
#include "fetch.h"
#include "utility.h"
#include "pipeline.h"
#include "instruction.h"
#include "DefinedTypes.h"

//fetches instruction from memory

// (Rini) confused - are we allowed to just access array elements from mem even though it is of the type uint32_t * (a pointer)?


//(Lize)
//needed: instruction after fetched called "fetched",
// also a _Bool tells if the reg contains fetched instruction, called "has_fetched"

uint32_t fetch(struct stateOfMachine ARM11) {
    uint8_t mem=ARM11.mem;
    uint32_t f = 0;
    uint32_t PC=(int) ARM11.registers[15];
    for (int i = 0; i < 4; i++) {
        f |= ((uint32_t) * (mem + PC + i) << (i * 8));
    }
    return f;
}