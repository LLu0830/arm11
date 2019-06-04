//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint>
#include "assembler_utility.h"

void set_bits(uint32 b, int pos, uint32_t val) {
    val <<= pos;
    uint32_t zeros = 0x0;
    zeros <<= pos;

    b &= zeros;
    b |= val;
}