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


bool checkCondition(struct stateOfMachine state, Cond condition) {
    //check condition fist
    uint32_t CPSRflag = state.registers[CPSRPosition];
    uint32_t VMasked = (CPSRflag >> 28) & V;
    uint32_t NMasked = (CPSRflag >> 28) & N;
    uint32_t ZMasked = (CPSRflag >> 28) & Z;
    uint32_t CMasked = (CPSRflag >> 28) & C;

    bool NEqualsV = (VMasked >> 3) == NMasked;
    switch (condition) {
        case EQ:
            if (ZMasked != 0) {
                return true;
            }
            break;
        case NE:
            if (ZMasked == 0) {
                return true;
            }
            break;
        case GE:
            if (NEqualsV) {
                return true;
            }
            break;
        case LT:
            if (!NEqualsV) {
                return true;
            }
            break;
        case GT:
            if (ZMasked == 0 && NEqualsV) {
                return true;
            }
            break;
        case LE:
            if ((ZMasked != 0) || !NEqualsV) {
                return true;
            }
            break;
    }
    return false;
}





void execute(instruction_type instruction, struct stateOfMachine state) {
    if (!checkCondition(state, instruction.conditionType)) {
        return;
        //instruction is ignored
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
