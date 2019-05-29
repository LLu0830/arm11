//
// Created by mw6118 on 26/05/19.
//

#include "instruction.h"
#include <stdint.h>
#include "pipeline.h"

//#ifndef C_GROUP_31_STATE_H
//#define C_GROUP_31_STATE_H

#define numOfRegisters 17;
#define numOfAddresses 65536;
#define CPSRPosition 16
#define PCPosition 15


struct stateOfMachine {
    uint32_t registers[17];
    uint8_t *mem;
};

<<<<<<< HEAD
#endif //C_GROUP_31_STATE_H
=======

//#endif //C_GROUP_31_STATE_H
>>>>>>> 84651c74bdb066eed4db975fabe2d5e7824acc9d
