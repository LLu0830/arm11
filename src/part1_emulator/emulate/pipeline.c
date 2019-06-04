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

    //fetching first Instruction
    struct pipes pipeP;

    struct pipes *pipe = &pipeP;

    //no Instruction has been fetched or decoded so far
    pipe->has_fetched = false;
    pipe->has_decoded = false;

    //three stage pipeline, terminates when ARM11 is not running
    while (pipe->decoded.instructionType != HLT) {

        //executes decoded Instruction
        if (pipe->has_decoded) {
            execute(pipe, ARM11);
        }
        //sets condition of loop to false, thus terminating the program


        //decoding fetched Instruction
        if (pipe->has_fetched) {
            pipe->decoded = decode(pipe->fetched);
            pipe->has_decoded = true;
        }

        //fetching new Instruction
        pipe->fetched = fetch(ARM11);
        pipe->has_fetched = true;

        //increasing program counter (PC)
        ARM11->registers[PCPosition] += 4;
    }
}

