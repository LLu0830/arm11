//
// Created by mw6118 on 26/05/19.
//

#include "instruction.h"
#ifndef C_GROUP_31_STATE_H
#define C_GROUP_31_STATE_H

#define int numOfRegisters = 12;
#define int numOfAddresses = 65536;


struct stateOfMachine{

    uint32_t registers[numOfRegisters];

    uint16_t ARMMemories[numOfAddresses];

    //?
   // CPSR CPSRState = new CPSR{0,0,0,0};

    int PC;
};


#endif //C_GROUP_31_STATE_H
