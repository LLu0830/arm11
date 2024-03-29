//
// Created by Rini Banerjee on 2019-05-25.
//


#ifndef SRC_EXECUTEDP_H
#define SRC_EXECUTEDP_H

#include "../emulator_utility/state.h"
#include "../emulator_utility/instruction.h"

void getValFromOp2(uint32_t op2, bool i, uint32_t *result, uint32_t *carryBit, struct stateOfMachine *ARM11);
uint32_t getResult(uint32_t opCode, uint32_t rnValue, uint32_t op2Value, bool *writeFlag);
void executeDP(Instruction instruction, struct stateOfMachine *ARM11);
void getValFromRegisterOp2(uint32_t op2, uint32_t *result, uint32_t *carryBit, struct stateOfMachine *ARM11);
void getValFromImmediateOp2(uint32_t op2, uint32_t *result);

#endif //SRC_EXECUTEDP_H
