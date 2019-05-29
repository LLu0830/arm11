//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "pipeline.h"
#include <stdlib.h>
#include <stdio.h>
#include "part1_emulator/emulator_utility/state.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/fetch/fetch.h"
#include "part1_emulator/decode/decode.h"
#include "part1_emulator/execute/execute.h"
#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulator_utility/DefinedTypes.h"
#include "part1_emulator/emulator_utility/utility.c"


#define PCPosition 15

//add pipeline

void pipeline(struct stateOfMachine ARM11) {


//    while() {
//        //execute
//        if (pipe.decoded.InstructionType != NUL) {
//            execute(pipe.decoded, ARM11);
//        }
//
//        //decode
//        if (pipe.has_fetched) {
//            decode(ARM11, pipe.fetched, pipe.decoded.conditionType);
//        }
//
//        //fetch
//        if (pipe.decoded.conditionType != HLT) {
//            ARM11.registers.fetched = fetch(ARM11);
//            pipe.has_fetched = true;
//        } else {
//            pipe.has_fetched = false;
//        }
//
//        //PC
//        //ARM11.registers[15] += 4;
//    }

    //decode
    //pipe.decoded=(uint32_t) 0;

    struct pipes pipe;
    pipe.instruction = fetch(ARM11);
    pipe.has_fetched = 0;
    //decode and execute

    if (pipe.has_fetched) {
        execute(ARM11, pipe.instruction);
    }
    //fetch
    //where does this address come from
    if (pipe.has_fetched && get_type(pipe.instruction) != HLT) {
        pipe.instruction = fetch(ARM11);
        pipe.has_fetched = true;
    }

    //PC
    ARM11.registers[PCPosition] += 4;

}

