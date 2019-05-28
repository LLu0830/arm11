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
#include "instruction.h"
#include "DefinedTypes.h"



//add pipeline

void pipeline(struct stateOfMachine ARM11,struct pipes pipe) {

    //execute
    if (pipe.decoded.InstructionType != NUL) {
        execute(pipe.decoded, ARM11);
    }


    //decode
    if (pipe.has_fetched) {
        decode(ARM11, pipe.fetched, pipe.decoded.conditionType);
    }

    //fetch
    //where does this address come from
    if (pipe.decoded.conditionType != HLT) {
        ARM11.registers.fetched = fetch(ARM11);
        pipe.has_fetched = true;
    } else {
        pipe.has_fetched = false;
    }

    //PC
    ARM11.registers[15] += 4;
}

