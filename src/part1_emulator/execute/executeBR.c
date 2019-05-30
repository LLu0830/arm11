//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "part1_emulator/emulator_utility/state.h"
#include "executeBR.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/emulator_utility/DefinedTypes.h"
#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulate/pipeline.h"

//pipeline has a side effect - PC is 8 bytes ahead of instruction
//being executed, therefore the pipeline offset has to be subtracted from address
//in PC value
#define pipelineOffset = 8;

//2's complement extend
int twos_complement_extend(int offset) {
    const int bits = 24;
    int mask = (1 << bits) - 1;
    _Bool is_negative = (offset & ~(mask >> 1)) != 0;
    offset |= -is_negative & ~mask;
    return offset;
}

void executeBR(uint32_t instruction, struct stateOfMachine *ARM11) {
    int cond = get_n_bits(instruction, 28, 4);
    int offset = get_n_bits(instruction, 0, 23);
    _Bool valid_cond = (cond == EQ || cond == NE || cond == GE || cond == LT || cond == GT || cond == LE ||
                        cond == AL);
    if (valid_cond) {
        //2's complement extend
        twos_complement_extend(offset);
        //add offset to PC
        ARM11->registers[PCPosition] += (twos_complement_extend(offset) - pipelineOffset);
    }
}


