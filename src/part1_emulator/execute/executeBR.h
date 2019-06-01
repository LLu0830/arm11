//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_EXECUTEBR_H
#define SRC_EXECUTEBR_H

#include "../emulate/pipeline.h"
#include "../emulator_utility/instruction.h"

uint32_t twos_complement_extend(uint32_t offset);
//int twos_complement_extend(int offset);
void executeBR(struct pipes *pipe, struct stateOfMachine *ARM11);

#endif //SRC_EXECUTEBR_H
