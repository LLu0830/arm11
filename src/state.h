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
    // CPSR is in registers[16]
    // when changing CPSR, 0001/0010/0100/1000, XOR operation(^)

    uint16_t ARMMemories[numOfAddresses];


    int PC;
};


#endif //C_GROUP_31_STATE_H
