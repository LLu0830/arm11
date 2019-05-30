//
// Created by Katarina Kulkova on 24.05.2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pipeline.h>
#include "execute.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"
#include "../emulator_utility/instruction.h"
#include "../emulator_utility/state.h"
#include "../emulator_utility/utility.h"

//executes all types of instructions

void execute(struct pipes *pipe, struct stateOfMachine *state) {
    if (!checkCondition(*state, pipe->decoded.conditionType)) {
        return;
        //instruction is ignored if the condition does not hold
    }
    InstructionType type = pipe->decoded.instructionType;

    switch (pipe->decoded.instructionType) {
        case DP:
            executeDP(pipe->decoded, *state);
            break;
        case MUL:
            executeMUL(pipe->decoded, state);
            break;
        case SDT:
            executeSDT(pipe->decoded, state);
            break;
        case BR:
            executeBR(pipe->decoded, *state);
            break;
        case HLT:
            return;
        default:
            break;
    }
}