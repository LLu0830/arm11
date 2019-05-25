//
// Created by Rini Banerjee on 2019-05-25.
//


// SUGGESTION: INCLUDE ASSERTION ERRORS TO MAKE SURE N AND START_POS ARE LESS THAN SIZE_OF(B)

#include "utility.h"
#include <stdlib.h>

int get_nth_bit(uint32_t b, int n) {
    return ((b >> (unsigned int) n) & 1U);
}

int get_four_bits(uint32_t b, int start_pos) {
    return ((b >> (unsigned int) start_pos) & 15U);
}