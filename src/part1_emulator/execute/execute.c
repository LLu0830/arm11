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

//(Rini) changed enum from char to 'plain' type, and moved to this C file from header file
// throwing errors - Manshu said she would change the number of instructionType enums we have so it's fine

//executes all types of instructions


//NEEDS CHANGING - CURRENTLY NOT COMPILING

void execute(stateOfMachine state, uint32_t fetched) {
    InstructionType type = get_type(fetched);
    Cond cond = get_n_bits(fetched, 28, 4);
    if (!checkCondition(state, cond)) {
        return;
        //instruction is ignored
    }

    switch (type) {
        case DP:
            executeDP(fetched, state);
            break;
        case MUL:
            executeMUL(fetched, state);
            break;
        case SDT:
            executeSDT(fetched, *state);
            break;
        case BR:
            executeBR(fetched, state);
            break;
        case HLT:
            return;
        default:
            break;
    }
}
