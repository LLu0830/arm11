//
// Created by Rini Banerjee on 2019-05-25.
//


#ifndef SRC_EXECUTEDP_H
#define SRC_EXECUTEDP_H

#include "state.h"

uint32_t getValFromOp2(uint32_t op2, uint32_t i);
void executeDP(struct stateOfMachine ARM11_registers, uint32_t instruction);

#endif //SRC_EXECUTEDP_H