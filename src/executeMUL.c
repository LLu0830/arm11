//
// Created by MANSHU WANG on 5/24/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>


#include "registers.h"
#include "memory.h"
#include "executeMUL.h"
#include "utility.h"
#include "DefinedTypes.h"
#include "instruction.h"
#include "state.h"


void executeMUL(instruction_type instruction, uint32_t fetched, struct stateOfMachine state) {
// check if condition field is satisfied

// get cond 4bits

    instruction.conditionType = 0xf & (fetched >> 28);

// holds the A bit
    instruction.accumulate = 0x1 & fetched >> 21;

// holds the S bit
    instruction.scc = 0x1 & fetched >> 20;

// rd,rn,rs,rm it should be a 4-bits address in the array registers, 0-12
    instruction.rd = fetched >> 16 & 0xf;

    instruction.rn = fetched >> 12 & 0xf;

    instruction.rs = fetched >> 8 & 0xf;

    instruction.rm = fetched & 0xf;


    uint32_t result;

    int positionRn = (int) (instruction.rn);
    int positionRm = (int)(instruction.rm);
    int positionRs = (int)(instruction.rs);
    int positionRd = (int)(instruction.rd);

    //registers[position] get the address in the memory???

    uint32_t valueRn = state.registers[positionRn];
    uint32_t valueRm = state.registers[positionRm];
    uint32_t valueRs = state.registers[positionRs];



    if (instruction.accumulate) {
        //Accumulate is set, performs a multiply and accumulate
        result = (valueRm) * (valueRs) + (valueRn);
    } else {
        // performs only multiply
        result = (valueRm) * (valueRs);
    }

    state.registers[positionRd] = result;


    if (instruction.scc) {
        // update N,Z flag in CPSR
        // N - the 31st bit of the result   Z - only if the result is zero
        if (result == 0) {
            state.registers[CPSRPosition] = (Z << 28) ^ state.registers[CPSRPosition];
        }

        //get 31bit, if equal to N, unchange // else update

        if ((result >> 31) != (registers[CPSRPosition] >> 31)) {
            state.registers[CPSRPosition] = (CPSR_helper.N << 28) ^ state.registers[CPSRPosition];
        }

    }


}


int binaryToDecimal(uint8_t binary_val) {
    int decimal_val = 0;
    int base = 1;
    int result = 0;
    uint8_t mask = 0x1;

    while (binary_val > 0) {
        if (mask & binary_val == 1) {
            decimal_val += base;
        }
        binary_val = binary_val >> 1;
        base *= 2;
    }

}

