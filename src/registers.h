//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdio.h>

#ifndef SRC_REGISTERS_H
#define SRC_REGISTERS_H

struct registers {
    uint32_t *reg;
    //uint32_t reg[17];

    int GP[32];
    int PC[32];
    int CPSR[32];
    int PC_int = *(reg + 15);
};

#endif //SRC_REGISTERS_H
