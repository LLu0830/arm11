//
// Created by Katarina Kulkova on 24.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "execute.h"
#include "registers.h"
#include "memory.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"

//(Rini) changed enum from char to 'plain' type, and moved to this C file from header file
enum instructionType {
    DP,
    MUL,
    SDT,
    BR
};


//executes all types of instructions
// (Rini) updated functions to make sure this file compiles
void execute(enum instructionType it, struct registers ARM11_registers, uint32_t b) {
    switch (it) {
        case DP:
            executeDP(ARM11_registers, b);
            break;
        case MUL:
            executeMUL(ARM11_registers, b);
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