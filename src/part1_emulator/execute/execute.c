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
#include "../emulator_utility/instruction.h"
#include "../emulator_utility/state.h"
#include "../emulator_utility/utility.h"

//executes all types of instructions

void execute(struct stateOfMachine *state, struct pipes pipe) {
    if (!checkCondition(state, pipe.instruction.conditionType)) {
        return;
        //instruction is ignored if the condition does not hold
    }
    switch (instruction.instructionType) {
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