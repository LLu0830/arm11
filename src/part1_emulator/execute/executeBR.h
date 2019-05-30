//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_EXECUTEBR_H
#define SRC_EXECUTEBR_H

#include "../emulator_utility/instruction.h"

int twos_complement_extend(int offset);
void executeBR(instruction_type instruction, struct stateOfMachine ARM11_registers);

#endif //SRC_EXECUTEBR_H
