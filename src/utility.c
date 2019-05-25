//
// Created by Rini Banerjee on 2019-05-25.
//


// SUGGESTION: INCLUDE ASSERTION ERRORS TO MAKE SURE N AND START_POS ARE LESS THAN SIZE_OF(B)

#include "utility.h"
#include <stdlib.h>
#include <math.h>

int read_n_bits(uint32_t b, int start_pos, int number_of_bits) {
    return ((b >> (unsigned int) start_pos) & (unsigned int) (pow(2, number_of_bits) - 1));
}

uint32_t write_one(uint32_t b, int pos) {
    return (b | 1U << (unsigned int) pos);
}