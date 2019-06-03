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

//pipeline has a side effect - PC is 8 bytes ahead of Instruction
//being executed, therefore the pipeline offset has to be subtracted from address
//in PC value
#define pipelineOffset = 8;

//2's complement extend
//int twos_complement_extend(int offset) {
//    const int bits = 24;
//    int mask = (1 << bits) - 1;
//    _Bool is_negative = (offset & ~(mask >> 1)) != 0;
//    offset |= -is_negative & ~mask;
//    return offset;
//}
//
//
//void executeBR(struct pipes *pipe, struct stateOfMachine *ARM11) {
//    int offset = pipe->decoded.offsets_or_operand2;
//    //2's complement extend
//    twos_complement_extend(offset);
//    //add offset to PC
//    pipe->has_fetched = false;
//    ARM11->registers[PCPosition] += (twos_complement_extend(offset));
//}


uint32_t twos_complement_extend(uint32_t offset) {
    offset <<= 2;
    if (offset >> 25) {
        offset |= ((1 << 6) - 1);
    }
    return offset;
}



//void executeBR(struct pipes *pipe, struct stateOfMachine *ARM11) {
//    uint32_t offset = pipe->decoded.offsets_or_operand2;
//    //2's complement extend
//    //add offset to PC
//    pipe->has_fetched = false;
//    pipe->has_decoded = false;
//    ARM11->registers[PCPosition] += (twos_complement_extend(offset));
//}

// Rini's attempt
void executeBR(struct pipes *pipe, struct stateOfMachine *ARM11) {
    uint32_t offset = pipe->decoded.offsets_or_operand2;

    offset = offset << 2;
    int bit23 = get_n_bits(offset, 23, 1);
    if (bit23) {
        uint32_t mask = 0xffU << 24U;
        offset = offset | mask;
    }
    pipe->has_fetched = false;
    pipe->has_decoded = false;
    ARM11->registers[PCPosition] = ARM11->registers[PCPosition] + offset;
}
