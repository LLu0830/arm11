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

void executeMUL(instruction_t instruction, uint32_t fetched) {
// check if condition field is satisfied

// get cond 4bits

    instruction.conditionType = 0xf & (fetched >> 28);

// holds the A bit
    instruction.accumulate = 0x1 & fetched >> 21;

// holds the S bit
    instruction.scc = 0x1 & fetched >> 20;

// rd,rn,rs,rm it should be a 4-bits address, I'm not sure about the type..
    instruction.rd = fetched >> 16 & 0xf;

    instruction.rn = fetched >> 12 & 0xf;

    instruction.rs = fetched >> 8 & 0xf;

    instruction.rm = fetched & 0xf;


    if (abit){
        //Accumulate is set, performs a multiply and accumulate

    } else {
        // performs only multiply


    }










}

