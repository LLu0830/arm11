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

uint32_t fetch(struct stateOfMachine ARM11, uint8_t *mem) {
    uint32_t f = 0;
    uint32_t PC=(int) ARM11.registers[15];
    f=(*mem+PC)|(*(mem+PC+1)<<8)|(*(mem+PC+2)<<16)|(*(mem+PC+2)<<24);
    return f;
}