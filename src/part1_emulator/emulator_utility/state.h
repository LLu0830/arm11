//
// Created by mw6118 on 26/05/19.
//


#include "instruction.h"
#include <stdint.h>
#include <stdbool.h>
//#include "part1_emulator/emulate/pipeline.h"

#ifndef C_GROUP_31_STATE_H
#define C_GROUP_31_STATE_H

#define numOfRegisters 17;
#define numOfAddresses 65536;
#define minAddress 0;
#define CPSRPosition 16
#define PCPosition 15


struct stateOfMachine {
    uint32_t registers[17];
    uint8_t *mem;
    bool running;
};

#endif //C_GROUP_31_STATE_H
