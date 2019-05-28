//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "state.h"
#include "utility.h"
#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "pipeline.h"


//add pipeline

void pipeline(struct stateOfMachine ARM11) {
    //execute
    if (ARM11.registers.decoded.InstructionType != NUL) {
        execute(decoded, ARM11);
    }

    //decode
    if (ARM11.registers.has_fetched) {
        decode(ARM11, fetched, instr);
    }

    //fetch
    if (ARM11.registers.registers.decoded.InstructionType != HLT) {
        ARM11.registers.fetched = fetch(*mem, address);
        ARM11.registers.has_fetched = 1;
    } else {
        ARM11.registers.has_fetched = 0;
    }

    //PC
    ARM11.registers.registers[15] += 4;
}