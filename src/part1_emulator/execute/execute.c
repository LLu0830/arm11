//
// Created by Katarina Kulkova on 24.05.2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "execute.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulator_utility/state.h"
#include <stdbool.h>
#include "part1_emulator/emulator_utility/DefinedTypes.h"

//executes all types of instructions
void execute(struct stateOfMachine *state, uint32_t instruction, InstructionType type) {
    Cond cond = get_n_bits(instruction, 28, 4);
    if (!checkCondition(*state, cond)) {
        return;
        //instruction is ignored if the condition does not hold
    }

    switch (type) {
        case DP:
            executeDP(instruction, *state);
            break;
        case MUL:
            executeMUL(instruction, *state);
            break;
        case SDT:
            executeSDT(instruction, *state);
            break;
        case BR:
            executeBR(instruction, *state);
            break;
        case HLT:
            return;
        default:
            break;
    }
}
