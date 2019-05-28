<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "registers.h"
#include "memory.h"
#include "executeBR.h"
#include "utility.h"

void twos_complement_extend(int offset) {
    const int bits = 24;
    int mask = (1 << bits) - 1;
    _Bool is_negative = (offset & ~(mask >> 1)) != 0;
    offset |= -is_negative & ~mask;
}

void executeBR(struct registers ARM11_registers, uint32_t b) {
    int cond = get_n_bits(b, 28, 4);
    int offset = get_n_bits(b, 0, 23);
    _Bool valid_cond = (cond == 0000 || cond == 0001 || cond == 1010 || cond == 1011 || cond == 1100 || cond == 1101 ||
                        cond == 1110);
    if (valid_cond) {
        //2's complement extend
        twos_complement_extend(offset);
        //add offset to PC
        ARM11_registers[15] += offset;
    }
}

//word_t negate(word_t value) {
//    return (~value) + 1;
//}
//
//word_t absolute(word_t value) {
//    if (is_negative(value)) {
//        return negate(value);
//    }
//    return value;
//}
//
//
//long twos_complement_to_long(word_t value) {
//    long result = absolute(value);
//
//    if (is_negative(value)) {
//        result *= -1;
//    }
//    return result;
//}

