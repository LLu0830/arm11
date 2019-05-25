//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>
#include "dataprocessing_execute.h"
#include "registers.h"
#include "utility.h"

// using utility function

void execute_data_processing(struct registers ARM11_registers, uint32_t b) {
    int i = get_n_bits(b, 25, 1);
    int opCode = get_n_bits(b, 21, 4);
    int s = get_n_bits(b, 20, 1);
    int rn = get_n_bits(b, 16, 4);
    int rd = get_n_bits(b, 12, 4);
    int op2 = get_n_bits(b, 0, 8);

    if (s == 1) {
        
    }
}