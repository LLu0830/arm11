//
// Created by mw6118 on 26/05/19.
//

#include "instruction.h"
#ifndef C_GROUP_31_STATE_H
#define C_GROUP_31_STATE_H

#define numOfRegisters 17;
#define numOfAddresses 65536;
#define CPSRPosition 16

struct stateOfMachine{

    uint32_t registers[numOfRegisters];
    // CPSR is in registers[16]

    uint16_t ARMMemories[numOfAddresses];


    int PC;
};


#endif //C_GROUP_31_STATE_H
