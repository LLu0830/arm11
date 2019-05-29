//
// Created by Rini Banerjee on 2019-05-25.
//


#ifndef SRC_EXECUTEDP_H
#define SRC_EXECUTEDP_H

#include "part1_emulator/emulator_utility/state.h"

void getValFromOp2(uint32_t op2, uint32_t i, uint32_t * result, uint32_t * carryBit);
void executeDP(uint32_t instruction, struct stateOfMachine ARM11);
void CFlagHelper(struct stateOfMachine state, uint32_t carryBit, OpCode operation, uint32_t i);

#endif //SRC_EXECUTEDP_H