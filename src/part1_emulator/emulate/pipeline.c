//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "pipeline.h"
#include <stdlib.h>
#include <stdio.h>
#include "../emulator_utility/utility.h"
#include "../fetch/fetch.h"
#include "../decode/decode.h"
#include "../execute/execute.h"
#include "../emulator_utility/DefinedTypes.h"

void pipeline(struct stateOfMachine *ARM11) {

    //fetching first instruction
    struct pipes pipe;

    //no instruction has been fetched or decoded so far
    pipe.has_fetched = false;
    pipe.has_decoded = false;

    //three stage pipeline, terminates when ARM11 is not running
    while (ARM11->running) {

        //executes decoded instruction
        if (pipe.decoded.instructionType != HLT) {
            if (pipe.has_decoded) {
                printf("Instruction: %X\n", pipe.fetched);
                printf("Ins Type: %X\n", HLT);
                execute(&pipe, ARM11);
            }
        } else {
            ARM11->running = false;
        }
        //sets condition of loop to false, thus terminating the program


        //decoding fetched instruction
        if (pipe.has_fetched) {
            pipe.decoded = decode(pipe.fetched);
            pipe.has_decoded = true;
        }

        //fetching new instruction
        pipe.fetched = fetch(ARM11, ARM11->registers[PCPosition]);
//        pipe.fetched = fetch(ARM11);
        pipe.has_fetched = true;

        //increasing program counter (PC)
        ARM11->registers[PCPosition] += 4;
    }
}

