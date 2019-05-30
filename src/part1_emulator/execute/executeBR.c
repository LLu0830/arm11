//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "part1_emulator/emulator_utility/state.h"
#include "memory.h"
#include "executeBR.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/emulator_utility/DefinedTypes.h"

#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulate/pipeline.h"


//2's complement extend
int twos_complement_extend(int offset) {
    const int bits = 24;
    int mask = (1 << bits) - 1;
    _Bool is_negative = (offset & ~(mask >> 1)) != 0;
    offset |= -is_negative & ~mask;
    return offset;
}


//LIZE NEEDS TO WORK ON THIS
void executeBR(instruction_type instruction, struct stateOfMachine ARM11_registers) {
    int cond = instruction.conditionType;
    int offset = instruction.offsets_or_operand2;
    _Bool valid_cond = (cond == EQ || cond == NE || cond == GE || cond == LT || cond == GT || cond == LE ||
                        cond == AL);
    if (valid_cond) {
        //2's complement extend
        twos_complement_extend(offset);
        //add offset to PC
        ARM11_registers.registers[15] += twos_complement_extend(offset);
    }
}


