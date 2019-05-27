//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "registers.h"
#include "memory.h"
#include "executeBR.h"
#include "utility.h"


void executeBR(struct registers ARM11_registers, uint32_t b) {
    int cond = get_n_bits(b, 28, 4);
    int offset = get_n_bits(b, 0, 23);
    _Bool valid_cond = (cond == 0000 || cond == 0001 || cond == 1010 || cond == 1011 || cond == 1100 || cond == 1101 ||
                        cond == 1110);
    if (valid_cond) {
        //2's complement extend
        const int bits = 24;
        int mask = (1 << bits) - 1;
        _Bool is_negative = (offset & ~(mask >> 1)) != 0;
        offset |= -is_negative & ~mask;

        //reg[PC] needs to be defined
        ARM11_registers.reg[PC]+=8;
        //twos_complement(offset);
    }

    // long twos_complement(int offset) {
    //     int offset[23]
    // }

//    uint32_t sign_extend(uint32_t x) {
//        uint32_t m = 1u << (24 - 1);
//        return (x ^ m) - m;
//    }
}

