//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdio.h>
#include "Manshu/DefinedTypes.h"
#ifndef SRC_REGISTERS_H
#define SRC_REGISTERS_H

struct registers {
    uint32_t *reg;

    register_address rd;
    register_address rn;
    register_address rs;
    register_address rm;
};

#endif //SRC_REGISTERS_H
