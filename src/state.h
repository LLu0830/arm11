//
// Created by mw6118 on 26/05/19.
//

#include "instruction.h"
#include <stdint.h>

#ifndef C_GROUP_31_STATE_H
#define C_GROUP_31_STATE_H

#define numOfRegisters 17;
#define numOfAddresses 65536;
#define CPSRPosition 16
#define PCPosition 15

struct stateOfMachine {
    struct registers registers;
    uint32_t *mem;
};


struct registers {
    uint32_t registers[17];
    uint32_t fetched[17];
    InstructionType decoded[17];
    _Bool has_fetched;
} registers;


#endif //C_GROUP_31_STATE_H
