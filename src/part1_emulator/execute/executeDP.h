//
// Created by Rini Banerjee on 2019-05-25.
//


#ifndef SRC_EXECUTEDP_H
#define SRC_EXECUTEDP_H

#include "../emulator_utility/state.h"
#include "../emulator_utility/instruction.h"

void getValFromOp2(uint32_t op2, uint32_t i, uint32_t * result, uint32_t * carryBit);
void executeDP(instruction_type instruction, struct stateOfMachine *ARM11);

#endif //SRC_EXECUTEDP_H
