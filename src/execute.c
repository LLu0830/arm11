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
#include "instruction.h"
#include "state.h"

//(Rini) changed enum from char to 'plain' type, and moved to this C file from header file
// throwing errors - Manshu said she would change the number of instructionType enums we have so it's fine

//executes all types of instructions

// (Rini) updated functions to make sure this file compiles
void execute(instruction_type instruction, struct stateOfMachine state) {

    switch (instruction.instructionType) {
        case DP:
            executeDP(instruction, state);
            break;
        case MUL:
            executeMUL(instruction, state);
            break;
        case SDT:
            executeSDT(instruction, state);
            break;
        case BR:
            executeBR(instruction, state);
            break;
        case HLT:
            return;
        default:
            break;
    }
}

//Comment for Manshu's eyes
