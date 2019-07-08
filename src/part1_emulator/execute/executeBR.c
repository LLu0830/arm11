//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "../emulator_utility/state.h"
#include "executeBR.h"
#include "../emulator_utility/utility.h"
#include "../emulator_utility/DefinedTypes.h"
#include "../emulator_utility/instruction.h"
#include "../emulate/pipeline.h"

void executeBR(struct pipes *pipe, struct stateOfMachine *ARM11) {
    uint32_t offset = pipe->decoded.offsets_or_operand2;

//    shifts offset by 2 to the left
    offset = offset << 2;
    int bit23 = get_n_bits(offset, 23, 1);
//    if the leftmost bit of the shifted offset is 1, it is extended to 32 bits with 1s using a mask
    if (bit23) {
        uint32_t mask = 0xffU << 24U;
        offset = offset | mask;
    }

    pipe->has_fetched = false;
    pipe->has_decoded = false;

//    PC position updated
    ARM11->registers[PCPosition] += offset;
}
