//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "pipeline.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../emulator_utility/state.h"
#include "../emulator_utility/utility.h"
#include "../fetch/fetch.h"
#include "../decode/decode.h"
#include "../execute/execute.h"
#include "../emulator_utility/instruction.h"
#include "../emulator_utility/DefinedTypes.h"

void pipeline(struct stateOfMachine ARM11) {

    //fetching first instruction
    struct pipes pipe;

    //no instruction has been fetched or decoded so far
    pipe.has_fetched = false;
    pipe.has_decoded = false;

    //three stage pipeline, terminates when ARM11 is not running
    while (ARM11.running) {

        //executes decoded instruction
        if (pipe.has_decoded && pipe.decodedType != HLT) {
            execute(*ARM11, pipe.toExecute, pipe.decodedType);
        }
        //sets condition of loop to false, thus terminating the program
        else {
            ARM11.running = false;
        }

        //decoding fetched instruction
        if (pipe.has_fetched) {
            pipe.toExecute = pipe.fetched;
            pipe.has_decoded = true;
            pipe.decodedType = get_type(pipe.toExecute);
        }

        //fetching new instruction
        pipe.fetched = fetch(ARM11, ARM11->registers[PCPosition]);
        pipe.has_fetched = true;

        //increasing program counter (PC)
        ARM11->registers[PCPosition] += 4;
    }
}

