//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "registers.h"
#include "memory.h"
#include "fetch.h"
#include "utility.h"

//fetches instruction from memory

// (Rini) confused - are we allowed to just access array elements from mem even though it is of the type uint32_t * (a pointer)?

uint32_t fetch(uint32_t *mem, int address) {
    return mem[address];
}



