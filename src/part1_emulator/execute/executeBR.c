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


void executeBR(instruction_type instruction, struct stateOfMachine ARM11_registers) {
    int cond = instruction.conditionType;
    int offset = instruction.offsets_or_operand2;
    //2's complement extend
    twos_complement_extend(offset);
    //add offset to PC
    ARM11_registers.registers[15] += twos_complement_extend(offset);


}


