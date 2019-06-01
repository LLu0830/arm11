//
// Created by Katarina Kulkova on 24.05.2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../emulate/pipeline.h"
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
    InstructionType type = pipe->decoded.instructionType;
    if (!checkCondition(*state, pipe->decoded.conditionType)) {
//        printf("fail in check condition\n");
        return;
        //instruction is ignored if the condition does not hold
    }

    switch (type) {
        case DP:
//            printf("is executing DP\n");
            executeDP(pipe->decoded, state);
            break;
        case MUL:
//            printf("is executing MUL\n");
            executeMUL(pipe->decoded, state);
            break;
        case SDT:
//            printf("is executing SDT\n");
            executeSDT(pipe->decoded, state);
            break;
        case BR:
//            printf("is executing BR\n");
            executeBR(pipe, state);
            break;
        case HLT:
//            printf("is executing HLT\n");
            return;
        default:
            break;
    }
}
