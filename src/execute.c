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
enum instructionType {
    DP,
    MUL,
    SDT,
    BR
};


//executes all types of instructions

// (Rini) updated functions to make sure this file compiles
void execute(instruction_type instruction, struct stateOfMachine state) {
    switch (instruction.instructionType) {
        case DP:
            executeDP(ARM11_registers, b);
            break;
        case MUL:
            executeMUL(instruction, state);
            break;
        case SDT:
            executeSDT(ARM11_registers, b);
            break;
        case BR:
            executeBR(ARM11_registers, b);
            break;
        default:
            break;
    }
}
