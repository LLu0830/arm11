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

<<<<<<<

HEAD

//add pipeline

void pipeline(struct stateOfMachine ARM11) {
    //execute
    if (ARM11.registers.decoded.InstructionType != NUL) {
        execute(decoded, ARM11);
    }

    //decode
    if (ARM11.registers.has_fetched) {
        decode(ARM11, fetched, ARM11.registers.registers.conditionType);
    }

    //fetch
    //where does this address come from
    if (ARM11.registers.registers.decoded.InstructionType != HLT) {
        ARM11.registers.fetched = fetch(ARM11.mem, address);
        ARM11.registers.has_fetched = 1;
    } else {
        ARM11.registers.has_fetched = 0;
    }

    //PC
    ARM11.registers.registers[15] += 4;
}

