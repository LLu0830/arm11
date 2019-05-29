//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "emulator_utility/state.h"
#include "memory.h"
#include "executeBR.h"
#include "emulator_utility/utility.h"
#include "emulator_utility/DefinedTypes.h"

#include "emulator_utility/instruction.h"
#include "emulate/pipeline.h"


//2's complement extend
int twos_complement_extend(int offset) {
    const int bits = 24;
    int mask = (1 << bits) - 1;
    _Bool is_negative = (offset & ~(mask >> 1)) != 0;
    offset |= -is_negative & ~mask;
    return offset;
}


void executeBR(struct stateOfMachine ARM11_registers, uint32_t b) {
    int cond = get_n_bits(b, 28, 4);
    int offset = get_n_bits(b, 0, 23);
    _Bool valid_cond = (cond == EQ || cond == NE || cond == GE || cond == LT || cond == GT || cond == LE ||
                        cond == AL);
    if (valid_cond) {
        //2's complement extend
        twos_complement_extend(offset);
        //add offset to PC
        ARM11_registers[15] += twos_complement_extend(offset);
    }
}


