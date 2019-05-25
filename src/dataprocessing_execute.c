//
// Created by Rini Banerjee on 2019-05-25.
//


#include <stdlib.h>
#include "dataprocessing_execute.h"
#include "registers.h"
#include "utility.h"

// using utility function
int getI(uint32_t b) {
    return get_nth_bit(b, 25);
}

int getOpCode(uint32_t b) {
    return get_four_bits(b, 21);
}

int getS(uint32_t b) {
    return get_nth_bit(b, 20);
}


void execute_data_processing(struct registers reg, int i, int opCode, int s, int rn, int rd, int op2) {

}